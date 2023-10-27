#pragma once
#include "CoreMinimal.h"
#include "EContentionRules.generated.h"

UENUM(BlueprintType)
namespace EContentionRules {
    enum Type {
        CR_MajorityWins,
        CR_OneTeamOnlyWins,
        CR_MAX UMETA(Hidden),
    };
}

