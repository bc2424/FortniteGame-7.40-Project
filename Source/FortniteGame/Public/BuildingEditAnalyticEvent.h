#pragma once
#include "CoreMinimal.h"
#include "EFortBuildingType.h"
#include "EFortResourceType.h"
#include "BuildingEditAnalyticEvent.generated.h"

USTRUCT(BlueprintType)
struct FBuildingEditAnalyticEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFortBuildingType::Type> BuildingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFortResourceType::Type> ResourceType;
    
    FORTNITEGAME_API FBuildingEditAnalyticEvent();
};

