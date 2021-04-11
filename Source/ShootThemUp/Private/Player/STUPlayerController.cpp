// Shoot Them Up game. All Rights Resived.

#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"

ASTUPlayerController::ASTUPlayerController()
{

    RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}