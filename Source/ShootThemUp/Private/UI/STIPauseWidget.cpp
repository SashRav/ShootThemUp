// Shoot Them Up game. All Rights Resived.


#include "UI/STIPauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"

void USTIPauseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &USTIPauseWidget::OnClearPause);
    }
}

void USTIPauseWidget::OnClearPause() {
    if (!GetWorld() || !GetWorld()->GetAuthGameMode())
        return;

    GetWorld()->GetAuthGameMode()->ClearPause();
    this->SetVisibility(ESlateVisibility::Hidden);
}