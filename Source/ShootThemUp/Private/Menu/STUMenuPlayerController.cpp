// Shoot Them Up game. All Rights Resived.

#include "Menu/STUMenuPlayerController.h"
#include "STUGameInstance.h"

void ASTUMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    this->ActivateTouchInterface(nullptr);

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;

}