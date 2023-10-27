#pragma once
#include "CoreMinimal.h"
#include "BuildingGameplayActorLockOnConsumable.h"
#include "BuildingGameplayActorBlade.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class ABuildingGameplayActorBlade : public ABuildingGameplayActorLockOnConsumable {
	GENERATED_BODY()
public:
	ABuildingGameplayActorBlade();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnPullStart();
    
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnPullAborted();
    
	UFUNCTION(NetMulticast, Reliable)
	void BroadcastOnPullStart();
    
	UFUNCTION(NetMulticast, Reliable)
	void BroadcastOnPullAborted();
    
};

