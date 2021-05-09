// Shoot Them Up game. All Rights Resived.

#include "Menu/STUMenuPlayerController.h"
#include "STUGameInstance.h"

void ASTUMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    const auto GameInstance = Cast<USTUGameInstance>(GetGameInstance());
    //GameInstance->SetTouchInterface(this->CurrentTouchInterface);

    this->ActivateTouchInterface(GameInstance->TouchInterface);

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;

}