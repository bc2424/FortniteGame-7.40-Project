#pragma once
#include "CoreMinimal.h"
#include "EUnlockRules.generated.h"

UENUM(BlueprintType)
namespace EUnlockRules {
    enum Type {
        UR_Reset,
        UR_MaintainState,
        UR_ResetDeactivate,
        UR_MAX UMETA(Hidden),
    };
}

