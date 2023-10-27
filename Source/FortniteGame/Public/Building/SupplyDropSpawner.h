#pragma once
#include "CoreMinimal.h"
#include "BuildingProp.h"
#include "SupplyDropSpawner.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class ASupplyDropSpawner : public ABuildingProp {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MinSpawnHeightOverride = 28000.00f;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MaxSpawnHeightOverride = 32000.00f;
};

