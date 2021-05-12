// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "STUSettingsWidget.generated.h"

class UButton;
class USpinBox;

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

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

    UFUNCTION()
    void SaveData();

    // UFUNCTION(BlueprintCallable, Category = "UI")
    // ESlateVisibility ReturnToMenu() const;

    virtual void NativeOnInitialized() override;

private:
};
