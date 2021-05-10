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

    FGameData GetGameData() const { return GameData; }

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* SaveButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ReturnButton;

    UPROPERTY(meta = (BindWidget))
    USpinBox* PlayersNumSpin;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetPlayersNumber() const { return GameData.PlayersNum; }

    UFUNCTION()
    void SetPlayersNumber();

    //UFUNCTION(BlueprintCallable, Category = "UI")
    //ESlateVisibility ReturnToMenu() const;

    virtual void NativeOnInitialized() override;

private:
    
};
