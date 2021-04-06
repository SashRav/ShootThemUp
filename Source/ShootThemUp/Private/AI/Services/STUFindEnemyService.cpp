// Shoot Them Up game. All Rights Resived.


#include "AI/Services/STUFindEnemyService.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUAIPerceptionComponent.h"

USTUFindEnemyService::USTUFindEnemyService() {
    NodeName = "Find Enemy";

}

 void USTUFindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
     
     const auto Blacboard = OwnerComp.GetBlackboardComponent();
     if (Blacboard)
     {
         const auto Controller = OwnerComp.GetAIOwner();
         const auto PerceptionComponent = STUUtils::GetSTUPlayerController<USTUAIPerceptionComponent>(Controller);
         if (PerceptionComponent)
         {
             Blacboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetColsestEnemy());
         }
     }

     Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
 }
