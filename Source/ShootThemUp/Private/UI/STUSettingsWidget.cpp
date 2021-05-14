// Shoot Them Up game. All Rights Resived.

#include "UI/STUSettingsWidget.h"
#include "Components/Button.h"
#include "Components/SpinBox.h"
#include "Components/ScrollBox.h"
#include "Components/CheckBox.h"
#include "STUCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "STUGameInstance.h"
#include "Menu/UI/STUMenuWidget.h"
#include "Menu/UI/STUadditionalSettings.h"
#include "Weapon/STURifleWeapon.h"

void USTUSettingsWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    const auto AdditionalSettingsWidgetCrated = CreateWidget<USTUadditionalSettings>(GetWorld(), AdditionalSettingsWidgetClass);

    const auto GameInstanse = Cast<USTUGameInstance>(GetWorld()->GetGameInstance());
    const auto NewGameData = GameInstanse->GameData;
    const auto NewRifleAmmoData = GameInstanse->GetRifleAmmoData();
    const auto NewLauncherAmmoData = GameInstanse->GetLauncherAmmoData();

    PlayersNumSpin->Value = NewGameData.PlayersNum;
    RoundsNumSpin->Value = NewGameData.RoundsNum;
    RoundsDuraionSpin->Value = NewGameData.RoindTime;

    AdditionalSettingsWidget = AdditionalSettingsWidgetCrated;
    AdditionalScrollBox->AddChild(AdditionalSettingsWidget);
    
    AdditionalSettingsWidget->AutoHealCheckBox->SetIsChecked(NewGameData.AutoHeal);
    AdditionalSettingsWidget->PlayersHealthSpin->Value = NewGameData.MaxHealth;

    AdditionalSettingsWidget->RifleAmmoSpin->Value = NewRifleAmmoData.Bullets;
    AdditionalSettingsWidget->RifleClipsSpin->Value = NewRifleAmmoData.Clips;
    AdditionalSettingsWidget->InfinityRifleAmmoCheckBox->SetIsChecked(NewRifleAmmoData.Infinite);

    AdditionalSettingsWidget->LauncherAmmoSpin->Value = NewLauncherAmmoData.Bullets;
    AdditionalSettingsWidget->LauncherClipsSpin->Value = NewLauncherAmmoData.Clips;

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

    RifleAmmoData.Bullets = AdditionalSettingsWidget->RifleAmmoSpin->GetValue();
    GameInstanse->SetRifleAmmo(RifleAmmoData);

    RifleAmmoData.Clips = AdditionalSettingsWidget->RifleClipsSpin->GetValue();
    GameInstanse->SetRifleClips(RifleAmmoData);

    RifleAmmoData.Infinite = AdditionalSettingsWidget->InfinityRifleAmmoCheckBox->IsChecked();
    GameInstanse->SetInfinityAmmo(RifleAmmoData);

    LaunchAmmoData.Bullets = AdditionalSettingsWidget->LauncherAmmoSpin->GetValue();
    GameInstanse->SetLauncherAmmo(LaunchAmmoData);

    LaunchAmmoData.Clips = AdditionalSettingsWidget->LauncherClipsSpin->GetValue();
    GameInstanse->SetLauncherClips(LaunchAmmoData);

    this->SetVisibility(ESlateVisibility::Hidden);
}