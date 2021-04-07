// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUHealthPercentecorator.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API USTUHealthPercentecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    USTUHealthPercentecorator();

    protected: 
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
        float HealthPercent = 0.6;

        virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
