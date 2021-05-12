// Shoot Them Up game. All Rights Resived.


#include "STUGameInstance.h"
#include "Sound/STUSoundFuncLib.h"


void USTUGameInstance::ToggleVolume() {
    USTUSoundFuncLib::ToggleSoundClassVolume(MasterSoundClass);
}