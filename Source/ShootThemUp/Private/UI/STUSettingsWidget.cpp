// Shoot Them Up game. All Rights Resived.

#include "UI/STUSettingsWidget.h"
#include "Components/Button.h"
#include "Components/SpinBox.h"
#include "STUCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Menu/UI/STUMenuWidget.h"

void USTUSettingsWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    PlayersNumSpin->Value = GameData.PlayersNum;

    if (SaveButton)
    {
        SaveButton->OnClicked.AddDynamic(this, &USTUSettingsWidget::SetPlayersNumber);
    }
  /*  if (ReturnButton)
    {
        ReturnButton->OnClicked.AddDynamic(this, &USTUSettingsWidget::ReturnToMenu);
    }*/
}

//ESlateVisibility USTUSettingsWidget::ReturnToMenu() const
//{
//    // this->SetVisibility(ESlateVisibility::Hidden);
//    return ESlateVisibility::Hidden;
//}

void USTUSettingsWidget::SetPlayersNumber()
{
    // GameData.PlayersNum = PlayersNumSlider->GetValue();
}