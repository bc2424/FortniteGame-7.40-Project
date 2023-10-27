#pragma once
#include "CoreMinimal.h"
#include "EFortResourceLevel.generated.h"

UENUM(BlueprintType)
namespace EFortResourceLevel {
    enum Type {
        First,
        Second,
        Third,
        Fourth,
        Fifth,
        Sixth,
        NumLevels,
        Invalid,
    };
}

