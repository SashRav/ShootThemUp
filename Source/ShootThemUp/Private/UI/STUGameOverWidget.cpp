// Shoot Them Up game. All Rights Resived.

#include "UI/STUGameOverWidget.h"
#include "STUGameModeBase.h"
#include "Player/STUPlayerState.h"
#include "UI/STUPlayerStatRawWidget.h"
#include "Components/VerticalBox.h"
#include "STUUtils.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USTUGameOverWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GetWorld())
    {
        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &USTUGameOverWidget::OnMatchStateChanged);
        }
    }

    if (ResetLevelButton)
    {
        ResetLevelButton->OnClicked.AddDynamic(this, &USTUGameOverWidget::OnResetLevel);
    }
}

void USTUGameOverWidget::OnMatchStateChanged(ESTUMatchState State)
{
    if (State == ESTUMatchState::GameOver)
    {
        UpdatePlayerStat();
    }

    const auto PlayerController = GetOwningPlayer();

    if (!PlayerController)
        return;

    PlayerController->ActivateTouchInterface(nullptr);
}
void USTUGameOverWidget::UpdatePlayerStat()
{
    if (!GetWorld() || !PlayerStatBox)
        return;

    PlayerStatBox->ClearChildren();

    for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        const auto Controller = It->Get();
        if (!Controller)
            continue;

        const auto PlayerState = Cast<ASTUPlayerState>(Controller->PlayerState);
        if (!PlayerState)
            continue;

        const auto PlayerStatRowWidget = CreateWidget<USTUPlayerStatRawWidget>(GetWorld(), PlayerStatRowWidgetClass);
        if (!PlayerStatRowWidget)
            continue;

        PlayerStatRowWidget->SetPlayerName(FText::FromString(PlayerState->GetPlayerName()));
        PlayerStatRowWidget->SetKills(STUUtils::TextFromInt(PlayerState->GetKillsNum()));
        PlayerStatRowWidget->SetDeaths(STUUtils::TextFromInt(PlayerState->GetDeathsNum()));
        PlayerStatRowWidget->SetTeam(STUUtils::TextFromInt(PlayerState->GetTeamID()));
        PlayerStatRowWidget->SetPlayerIndicatorVisibility(Controller->IsPlayerController());
        PlayerStatRowWidget->SetTeamColor(PlayerState->GetTeamColor());

        PlayerStatBox->AddChild(PlayerStatRowWidget);
    }
}

void USTUGameOverWidget::OnResetLevel()
{
    // const FName CurrentLevelName = "TestLevel";
    const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
    UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}