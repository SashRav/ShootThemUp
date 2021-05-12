// Shoot Them Up game. All Rights Resived.

#include "UI/STUSettingsWidget.h"
#include "Components/Button.h"
#include "Components/SpinBox.h"
#include "Components/ScrollBox.h"
#include "Components/CheckBox.h"
#include "STUCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Menu/UI/STUMenuWidget.h"
#include "STUGameInstance.h"
#include "Menu/UI/STUadditionalSettings.h"

void USTUSettingsWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    const auto GameInstanse = Cast<USTUGameInstance>(GetWorld()->GetGameInstance());
    const auto NewGameData = GameInstanse->GameData;
    const auto AdditionalSettingsWidgetCrated = CreateWidget<USTUadditionalSettings>(GetWorld(), AdditionalSettingsWidgetClass);

    PlayersNumSpin->Value = NewGameData.PlayersNum;
    RoundsNumSpin->Value = NewGameData.RoundsNum;
    RoundsDuraionSpin->Value = NewGameData.RoindTime;

    AdditionalSettingsWidget = AdditionalSettingsWidgetCrated;
    AdditionalScrollBox->AddChild(AdditionalSettingsWidget);
    
    AdditionalSettingsWidget->AutoHealCheckBox->SetIsChecked(NewGameData.AutoHeal);
    AdditionalSettingsWidget->PlayersHealthSpin->Value = NewGameData.MaxHealth;

    if (SaveButton)
    {
        SaveButton->OnClicked.AddDynamic(this, &USTUSettingsWidget::SaveData);
        //SaveButton->OnClicked.AddDynamic(AdditionalSettingsWidget, &USTUadditionalSettings::SaveAdditionalData);
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

    GameData.MaxHealth = AdditionalSettingsWidget->PlayersHealthSpin->GetValue();
    GameInstanse->SetMaxHealth(GameData);

    GameData.AutoHeal = AdditionalSettingsWidget->AutoHealCheckBox->IsChecked();
    GameInstanse->SetAutoHeal(GameData);

    this->SetVisibility(ESlateVisibility::Hidden);
}