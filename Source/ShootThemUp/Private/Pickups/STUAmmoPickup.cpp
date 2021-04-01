// Shoot Them Up game. All Rights Resived.


#include "Pickups/STUAmmoPickup.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);


bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn) {
    
    UE_LOG(LogAmmoPickup, Display, TEXT("Ammo was taken"));
    return true;
}