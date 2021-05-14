// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "Menu/UI/STUadditionalSettings.h"
#include "Weapon/STURifleWeapon.h"
#include "STUSettingsWidget.generated.h"

class UButton;
class USpinBox;
class UScrollBox;

UCLASS()
class SHOOTTHEMUP_API USTUSettingsWidget : public USTUBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* SaveButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ReturnButton;

    UPROPERTY(meta = (BindWidget))
    USpinBox* PlayersNumSpin;

    UPROPERTY(meta = (BindWidget))
    USpinBox* RoundsNumSpin;

    UPROPERTY(meta = (BindWidget))
    USpinBox* RoundsDuraionSpin;

    UPROPERTY(meta = (BindWidget))
    UScrollBox* AdditionalScrollBox;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> AdditionalSettingsWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<ASTURifleWeapon> RifleWeapon;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FRifleAmmoData RifleAmmoData;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FLauncherAmmoData LaunchAmmoData;

    UFUNCTION()
    void SaveData();

    // UFUNCTION(BlueprintCallable, Category = "UI")
    // ESlateVisibility ReturnToMenu() const;

    virtual void NativeOnInitialized() override;

private:
    USTUadditionalSettings* AdditionalSettingsWidget;
};
