// Shoot Them Up game. All Rights Resived.


#include "UI/STIPauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"

bool USTIPauseWidget::Initialize() {
    const auto InitStatus = Super::Initialize();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &USTIPauseWidget::OnClearPause);
    }

    return InitStatus;
}

void USTIPauseWidget::OnClearPause() {
    if (!GetWorld() || !GetWorld()->GetAuthGameMode())
        return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}