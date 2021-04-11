// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STIPauseWidget.generated.h"

class UButton;

UCLASS()
class SHOOTTHEMUP_API USTIPauseWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* ClearPauseButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnClearPause();
};
