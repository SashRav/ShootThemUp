// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "Weapon/STURifleWeapon.h"
#include "STUadditionalSettings.generated.h"

class UCheckBox;
class USpinBox;

UCLASS()
class SHOOTTHEMUP_API USTUadditionalSettings : public UUserWidget
{
    GENERATED_BODY()

public:
    void SaveAdditionalData();


    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

    UPROPERTY(meta = (BindWidget))
    USpinBox* PlayersHealthSpin;

    UPROPERTY(meta = (BindWidget))
    UCheckBox* AutoHealCheckBox;
    
    UPROPERTY(meta = (BindWidget))
    USpinBox* RifleAmmoSpin;

    UPROPERTY(meta = (BindWidget))
    USpinBox* RifleClipsSpin;

    UPROPERTY(meta = (BindWidget))
    UCheckBox* InfinityRifleAmmoCheckBox;

    UPROPERTY(meta = (BindWidget))
    USpinBox* LauncherAmmoSpin;

    UPROPERTY(meta = (BindWidget))
    USpinBox* LauncherClipsSpin;
};
