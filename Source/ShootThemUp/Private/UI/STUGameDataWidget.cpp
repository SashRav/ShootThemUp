// Shoot Them Up game. All Rights Resived.

#include "UI/STUGameDataWidget.h"
#include "STUGameModeBase.h"
#include "Player/STUPlayerState.h"
#include "STUGameInstance.h"



int32 USTUGameDataWidget::GetCurrentRoundNum() const
{
    const auto GameMode = GetSTUGameMode();
    return GameMode ? GameMode->GetCurrentRoundNum() : 0;
    
}

int32 USTUGameDataWidget::GetTotalRoundsNum() const
{
    const auto GameInstanse = GetSTUGameInstance();
    const auto NewGameData = GameInstanse->GetGameData();

    return NewGameData.RoundsNum;

   /* const auto GameMode = GetSTUGameMode();
    return GameMode ? GameMode->GetGameData().RoundsNum : 0;*/
}

int32 USTUGameDataWidget::GetRoundSecondsRemaining() const
{
    const auto GameMode = GetSTUGameMode();
    return GameMode ? GameMode->GetRoundSecondsRemaining() : 0;
}

ASTUGameModeBase* USTUGameDataWidget::GetSTUGameMode() const
{
    return GetWorld() ? Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}
ASTUPlayerState* USTUGameDataWidget::GetSTUPlayerState() const
{
    return GetOwningPlayer() ? Cast<ASTUPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}

USTUGameInstance* USTUGameDataWidget::GetSTUGameInstance() const
{
    return GetWorld() ? Cast<USTUGameInstance>(GetGameInstance()) : nullptr;
}