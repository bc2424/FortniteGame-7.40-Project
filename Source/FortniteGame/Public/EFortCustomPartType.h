#pragma once
#include "CoreMinimal.h"
#include "EFortCustomPartType.generated.h"

UENUM(BlueprintType)
namespace EFortCustomPartType {
    enum Type {
        Head,
        Body,
        Hat,
        Backpack,
        Charm,
        Face,
        NumTypes,
    };
}

