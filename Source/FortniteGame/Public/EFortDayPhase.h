#pragma once
#include "CoreMinimal.h"
#include "EFortDayPhase.generated.h"

UENUM(BlueprintType)
namespace EFortDayPhase {
    enum Type {
        Morning,
        Day,
        Evening,
        Night,
        NumPhases,
    };
}

