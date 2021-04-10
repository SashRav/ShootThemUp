// Shoot Them Up game. All Rights Resived.


#include "Player/STUPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUPlayerState, All, All);

 void ASTUPlayerState::LogInfo()
{
     UE_LOG(LogSTUPlayerState, Display, TEXT("TeamId: %i, Kills: %i, Deaths: %i"), TeamID, KillsNum, DeathsNum);
 }