// Shoot Them Up game. All Rights Resived.

#include "Pickups/STUBasePickup.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickup, All, All);

// Sets default values
ASTUBasePickup::ASTUBasePickup()
{
    PrimaryActorTick.bCanEverTick = true;
    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);
}

// Called when the game starts or when spawned
void ASTUBasePickup::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASTUBasePickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASTUBasePickup::NotifyActorBeginOverlap(AActor* OtherActor) {
    Super::NotifyActorBeginOverlap(OtherActor);

    UE_LOG(LogBasePickup, Display, TEXT("Pickup was taken"));
    Destroy();
 }