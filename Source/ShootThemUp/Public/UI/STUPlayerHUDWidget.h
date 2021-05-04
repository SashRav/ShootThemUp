// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "Components/STUWeaponComponent.h"
#include "STUCoreTypes.h"

#include "STUPlayerHUDWidget.generated.h"

class UProgressBar;
class UButton;
class APawn;

UCLASS()
class SHOOTTHEMUP_API USTUPlayerHUDWidget : public USTUBaseWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    float GetHealthPercent() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetCurrentWeaponUIData(FWeaponUIData& UIData) const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsPlayerAlive() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsPlayerSectating() const;

    UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void OnTakeDamage();

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetKillsNum() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    FString FormatBullets(int32 BulletsNum) const;
    
protected:
    UPROPERTY(meta = (BindWidget))
    UProgressBar* HealthProgressBar;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* DamageAnimation;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    float PercentColorThreshold = 0.3f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    FLinearColor GoodColor = FLinearColor::White;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    FLinearColor BadColor = FLinearColor::Red;

    virtual void NativeOnInitialized() override;

    // Additional buttons

    UPROPERTY(meta = (BindWidget))
    UButton* FireButton;

    UPROPERTY(meta = (BindWidget))
    UButton* JumpButton;

    UPROPERTY(meta = (BindWidget))
    UButton* RunButton;

    UPROPERTY(meta = (BindWidget))
    UButton* NextWeaponButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ReloadButton;

    UPROPERTY(meta = (BindWidget))
    UButton* PauseButton;

private:
    void OnHealthChanged(float Health, float HelthDelta);
    void OnNewPawn(APawn* NewPawn);
    void UpdateHealthBar();
};
