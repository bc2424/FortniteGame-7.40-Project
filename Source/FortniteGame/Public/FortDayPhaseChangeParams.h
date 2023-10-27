#pragma once
#include "CoreMinimal.h"
#include "EFortDayPhase.h"
#include "FortMissionEventParams.h"
#include "FortDayPhaseChangeParams.generated.h"

class AFortTimeOfDayManager;
class UFortDayPhaseChangeParams;

UCLASS(Blueprintable)
class UFortDayPhaseChangeParams : public UFortMissionEventParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFortTimeOfDayManager* LightingAndFogManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFortDayPhase::Type> NewDayPhase;
    
    UFortDayPhaseChangeParams();
    UFUNCTION(BlueprintCallable)
    void SetParams(AFortTimeOfDayManager* _LightingAndFogManager, TEnumAsByte<EFortDayPhase::Type> _NewDayPhase, UFortDayPhaseChangeParams*& ThisParam);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void BreakParams(AFortTimeOfDayManager*& _LightingAndFogManager, TEnumAsByte<EFortDayPhase::Type>& _NewDayPhase);
    
};

