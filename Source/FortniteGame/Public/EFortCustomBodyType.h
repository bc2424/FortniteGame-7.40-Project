#pragma once
#include "CoreMinimal.h"
#include "EFortCustomBodyType.generated.h"

UENUM(BlueprintType)
namespace EFortCustomBodyType {
    enum Type {
        Small = 0x1,
        Medium,
        MediumAndSmall,
        Large,
        LargeAndSmall,
        LargeAndMedium,
        All,
        Deprecated,
    };
}

