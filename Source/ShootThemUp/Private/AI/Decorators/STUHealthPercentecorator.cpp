// Shoot Them Up game. All Rights Resived.


#include "AI/Decorators/STUHealthPercentecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"


USTUHealthPercentecorator::USTUHealthPercentecorator() {
    NodeName = "Health Percent";
}

bool USTUHealthPercentecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const {

    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller)
        return false;

    const auto HealthComponent = STUUtils::GetSTUPlayerController<USTUHealthComponent>(Controller->GetPawn());
    if (!HealthComponent || HealthComponent->IsDead())
        return false;

    return HealthComponent->GetHealthPercent() <= HealthPercent;
}