// Shoot Them Up game. All Rights Resived.

#include "Components/STUHealthComponent.h"

USTUHealthComponent::USTUHealthComponent()
{

    PrimaryComponentTick.bCanEverTick = false;
}

void USTUHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
}
