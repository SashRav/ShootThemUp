// Shoot Them Up game. All Rights Resived.

#include "UI/STUSettingsWidget.h"
#include "Components/Button.h"
#include "Components/SpinBox.h"
#include "STUCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Menu/UI/STUMenuWidget.h"
#include "STUGameInstance.h"

void USTUSettingsWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

     const auto GameInstanse = Cast<USTUGameInstance>(GetWorld()->GetGameInstance());
    const auto NewGameData = GameInstanse->GameData;

    PlayersNumSpin->Value = NewGameData.PlayersNum;
    RoundsNumSpin->Value = NewGameData.RoundsNum;
    RoundsDuraionSpin->Value = NewGameData.RoindTime;

    if (SaveButton)
    {
        SaveButton->OnClicked.AddDynamic(this, &USTUSettingsWidget::SaveData);
    }
}

void USTUSettingsWidget::SaveData()
{
    const auto GameInstanse = Cast<USTUGameInstance>(GetWorld()->GetGameInstance());
    
    GameData.PlayersNum =  PlayersNumSpin->GetValue();
    GameInstanse->SetPlayersNumber(GameData);

    GameData.RoundsNum = RoundsNumSpin->GetValue();
    GameInstanse->SetRoundsNumber(GameData);

    GameData.RoindTime = RoundsDuraionSpin->GetValue();
    GameInstanse->SetRoundsDuration(GameData);

    this->SetVisibility(ESlateVisibility::Hidden);
}