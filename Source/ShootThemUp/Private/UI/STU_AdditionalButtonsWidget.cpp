// Shoot Them Up game. All Rights Resived.

#include "UI/STU_AdditionalButtonsWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"
#include "EngineUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTU_AdditionalButtonsWidget, All, All);

void USTU_AdditionalButtonsWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (FireButton)
    {
        FireButton->OnClicked.AddDynamic(this, &USTU_AdditionalButtonsWidget::OnStartFirePressed);
        FireButton->OnReleased.AddDynamic(this, &USTU_AdditionalButtonsWidget::OnStopFire);
    }
}

void USTU_AdditionalButtonsWidget::OnStartFirePressed()
{
    if (!GetWorld())
        return;

   

  

    //const auto WeaponCompoenent = STUUtils::GetSTUPlayerController<USTUWeaponComponent>();
        
     UE_LOG(LogSTU_AdditionalButtonsWidget, Display, TEXT("Pawn: %s"), *GetOwningPlayer()->GetFName().ToString());

      //WeaponCompoenent->StartFire();

   /* for (auto Pawn : TActorRange<APawn>(GetWorld()))
    {
        const auto WeaponCompoenent = STUUtils::GetSTUPlayerController<USTUWeaponComponent>(Pawn);
        if (!WeaponCompoenent)
            continue;

       
    }*/
}

void USTU_AdditionalButtonsWidget::OnStopFire()
{
    if (!GetWorld())
        return;

    UE_LOG(LogSTU_AdditionalButtonsWidget, Display, TEXT("Pressed"));
}