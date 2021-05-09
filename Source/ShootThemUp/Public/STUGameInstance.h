// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUCoreTypes.h"
#include "InputCoreTypes.h"
#include "STUGameInstance.generated.h"

class USoundClass;
class UTouchInterface;

UCLASS()
class SHOOTTHEMUP_API USTUGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    FLevelData GetStartupLevel() const { return StartupLevel; }
    void SetStartupLevel(const FLevelData& Data) { StartupLevel = Data; }

    TArray<FLevelData> GetLevelsData() const { return LevelsData; }

    void ToggleVolume();

    FName GetMenuLevelName() const { return MenuLevelName; }

    void SetTouchInterface(UTouchInterface* STouchInterface) { TouchInterface = STouchInterface; }

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UTouchInterface* TouchInterface;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game", meta = (ToolTip = "Level names must be uniqe!"))
    TArray<FLevelData> LevelsData;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FName MenuLevelName = NAME_None;

    UPROPERTY(EditDefaultsOnly, Category = "Sound")
    USoundClass* MasterSoundClass;



private:
    FLevelData StartupLevel;
};
