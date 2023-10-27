#pragma once
#include "CoreMinimal.h"
#include "EFortCombatThresholds.generated.h"

UENUM(BlueprintType)
namespace EFortCombatThresholds {
    enum Type {
        Low,
        Medium,
        High,
        Extreme,
        Max_None,
    };
}

