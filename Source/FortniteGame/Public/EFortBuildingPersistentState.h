#pragma once
#include "CoreMinimal.h"
#include "EFortBuildingPersistentState.generated.h"

UENUM(BlueprintType)
namespace EFortBuildingPersistentState {
    enum Type {
        Default,
        New,
        Constructed,
        Destroyed,
        Searched,
        None,
    };
}

