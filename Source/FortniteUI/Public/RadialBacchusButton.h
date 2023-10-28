#pragma once
#include "CoreMinimal.h"
#include "EGameplayCueEvent.h"
#include "GameplayCueParameters.h"
#include "FortHUDElementWidget.h"
#include "RadialBacchusButton.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URadialBacchusButton : public UFortHUDElementWidget {
    GENERATED_BODY()
public:
    URadialBacchusButton();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateCooldown_Blueprint();
    
    UFUNCTION(BlueprintCallable)
    void StopUpdateCooldown();
    
    UFUNCTION(BlueprintCallable)
    void StartUpdateCooldown();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRadialProgressEvent_Blueprint(FName EventName, TEnumAsByte<EGameplayCueEvent::Type> EventType, const FGameplayCueParameters& Parameters);
    
    UFUNCTION(BlueprintCallable)
    void ReceiveRadialProgressEvent(FName EventName, TEnumAsByte<EGameplayCueEvent::Type> EventType, const FGameplayCueParameters& Parameters);
    
};

