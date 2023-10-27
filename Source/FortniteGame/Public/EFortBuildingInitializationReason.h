#pragma once
#include "CoreMinimal.h"
#include "EFortBuildingInitializationReason.generated.h"

UENUM(BlueprintType)
namespace EFortBuildingInitializationReason {
    enum Type {
        StaticallyPlaced,
        Spawned,
        Replaced,
        LoadedFromSave,
        DynamicBuilderPlaced,
        PlacementTool,
        TrapTool,
        None,
    };
}

