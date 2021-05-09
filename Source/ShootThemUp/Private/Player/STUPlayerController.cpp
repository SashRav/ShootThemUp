// Shoot Them Up game. All Rights Resived.

#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"
#include "STUGameModeBase.h"
#include "STUGameInstance.h"
#include "UI/STUGameHUD.h"

DEFINE_LOG_CATEGORY_STATIC(LogASTUPlayerController, All, All);

ASTUPlayerController::ASTUPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}

void ASTUPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    OnNewPawn.Broadcast(InPawn);
}

void ASTUPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        const auto STUGameInstanse = GetWorld()->GetGameInstance<USTUGameInstance>();
        if (!STUGameInstanse)
            return;

        // ActivateTouchInterface(STUGameInstanse->TouchInterface);

        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ASTUPlayerController::OnMatchStateChanged);
        }
    }
}

void ASTUPlayerController::OnMatchStateChanged(ESTUMatchState State)
{
    const auto STUGameInstanse = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstanse)
        return;

    if (State == ESTUMatchState::InProgress)
    {
        ActivateTouchInterface(STUGameInstanse->TouchInterface);

        SetInputMode(FInputModeGameAndUI());
        bShowMouseCursor = false;
    }
    else
    {
        ActivateTouchInterface(nullptr);

        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}

void ASTUPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent)
        return;

    InputComponent->BindAction("PauseGame", IE_Pressed, this, &ASTUPlayerController::OnPauseGame);
    InputComponent->BindAction("Mute", IE_Pressed, this, &ASTUPlayerController::OnMuteSound);
}

void ASTUPlayerController::OnPauseGame()
{
    UE_LOG(LogASTUPlayerController, Display, TEXT("Works"));
    if (!GetWorld() || !GetWorld()->GetAuthGameMode())
        return;
    GetWorld()->GetAuthGameMode()->SetPause(this);
}

void ASTUPlayerController::OnMuteSound()
{
    if (!GetWorld())
        return;

    const auto STUGameInstanse = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstanse)
        return;

    STUGameInstanse->ToggleVolume();
}