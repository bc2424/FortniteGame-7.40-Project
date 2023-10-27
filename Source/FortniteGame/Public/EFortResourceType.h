#pragma once
#include "CoreMinimal.h"
#include "EFortResourceType.generated.h"

UENUM(BlueprintType)
namespace EFortResourceType {
    enum Type {
        Wood,
        Stone,
        Metal,
        Permanite,
        None,
    };
}

