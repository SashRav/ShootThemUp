// Shoot Them Up game. All Rights Resived.


#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthComponent.h"

float USTUPlayerHUDWidget::GetHealthPercent() const {
    const auto Player = GetOwningPlayerPawn();
    if (!Player)
        return 0.0f;

    const auto Component = Player->GetComponentByClass(USTUHealthComponent::StaticClass());
    const auto HealthComponent = Cast<USTUHealthComponent>(Component);
    if (!HealthComponent)
        return 0.0f;

    return HealthComponent->GetHealthPercent();
}