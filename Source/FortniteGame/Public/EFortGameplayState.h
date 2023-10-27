#pragma once
#include "CoreMinimal.h"
#include "EFortGameplayState.generated.h"

UENUM(BlueprintType)
namespace EFortGameplayState {
    enum Type {
        NormalGameplay,
        WaitingToStart,
        EndOfZone,
        EnteringZone,
        LeavingZone,
        Invalid,
    };
}

