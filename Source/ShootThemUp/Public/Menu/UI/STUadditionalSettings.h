// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
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
};
