// Shoot Them Up game. All Rights Resived.


#include "Menu/UI/STUadditionalSettings.h"
#include "STUGameInstance.h"
#include "Components/SpinBox.h"
#include "Components/CheckBox.h"


void USTUadditionalSettings::SaveAdditionalData() {

    const auto GameInstanse = Cast<USTUGameInstance>(GetWorld()->GetGameInstance());
    
    GameData.MaxHealth = PlayersHealthSpin->GetValue();
    GameInstanse->SetMaxHealth(GameData);

    GameData.AutoHeal = AutoHealCheckBox->IsChecked();
    GameInstanse->SetAutoHeal(GameData);

}