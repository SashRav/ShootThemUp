// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STU_AdditionalButtonsWidget.generated.h"

class UButton;

UCLASS()
class SHOOTTHEMUP_API USTU_AdditionalButtonsWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* FireButton;

    virtual void NativeOnInitialized() override;

    public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    void OnStartFirePressed();

private:


    UFUNCTION()
    void OnStopFire();
};
