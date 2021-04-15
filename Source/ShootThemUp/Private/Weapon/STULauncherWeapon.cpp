// Shoot Them Up game. All Rights Resived.


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjectile.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

void ASTULauncherWeapon::StartFire() {
    MakeShot();
}

void ASTULauncherWeapon::MakeShot()
{
    if (!GetWorld())
        return;

    if (IsAmmoEmpty())
    {
        UGameplayStatics::SpawnSoundAtLocation(GetWorld(), NoAmmoSound, GetActorLocation());

        return;
    }

    FVector TraceStart, TraceEnd;
    if (!GetTraceData(TraceStart, TraceEnd))
        return;

    FHitResult HitResult;
    MakeHit(HitResult, TraceStart, TraceEnd);

    const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
    const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    ASTUProjectile* Projectile = GetWorld()->SpawnActorDeferred<ASTUProjectile>(ProjectileClass, SpawnTransform);
    if (Projectile)
    {
        Projectile->SetShotDirection(Direction);
        Projectile->SetOwner(GetOwner());
        Projectile->FinishSpawning(SpawnTransform);
    }

    DecreaseAmmo();
    SpawnMuzzleFX();
    UGameplayStatics::SpawnSoundAttached(FireSound, WeaponMesh, MuzzleSoketName);

}