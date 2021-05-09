// Shoot Them Up game. All Rights Resived.


#include "UI/STUSpectatorWidget.h"
#include "STUUtils.h"
#include "Components/STURespawnComponent.h"

bool USTUSpectatorWidget::GetRespawnTime(int32& CountDownTime) const
{
    const auto RespawnComponent = STUUtils::GetSTUPlayerController<USTURespawnComponent>(GetOwningPlayer());
    const auto PlayerController = GetOwningPlayer();

    if (!RespawnComponent || !RespawnComponent->IsRespawnInProgress())
        return false;
    
    CountDownTime = RespawnComponent->GetRespawnCountDown();
    return true;
}