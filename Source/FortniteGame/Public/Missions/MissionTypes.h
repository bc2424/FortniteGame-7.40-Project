#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FortWorldItemDefinition.h"
#include "FortMission.h"
#include "FortPlayerController.h"
#include "MissionTypes.generated.h"

class AFortMission;
class UFortMissionFailedParams;

UCLASS(Blueprintable, MinimalAPI, NotPlaceable)
class UFortMissionEventParams : public UObject {
	GENERATED_BODY()
public:
};

UCLASS(Blueprintable)
class UFortMissionFailedParams : public UFortMissionEventParams {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	AFortMission* FailedMission;
    
	UFortMissionFailedParams();
	UFUNCTION(BlueprintCallable)
	void SetParams(AFortMission* _FailedMission, UFortMissionFailedParams*& ThisParam);
    
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void BreakParams(AFortMission*& _FailedMission);
};

UCLASS(Blueprintable)
class UFortItemDroppedParams : public UFortMissionEventParams {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortWorldItemDefinition* DroppedItemDefinition;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	AFortPlayerController* DroppedBy;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 AmountDropped;
    
	UFortItemDroppedParams();
	UFUNCTION(BlueprintCallable)
	void SetParams(const UFortWorldItemDefinition* _DroppedItemDefinition, AFortPlayerController* _DroppedBy, int32 _AmountCollected, UFortItemDroppedParams*& ThisParam);
    
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void BreakParams(UFortWorldItemDefinition*& _DroppedItemDefinition, AFortPlayerController*& _DroppedBy, int32& _AmountCollected);
};

