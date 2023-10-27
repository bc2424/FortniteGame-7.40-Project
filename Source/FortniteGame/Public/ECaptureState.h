#pragma once
#include "CoreMinimal.h"
#include "ECaptureState.generated.h"

UENUM(BlueprintType)
namespace ECaptureState {
    enum Type {
        CS_Idle,
        CS_Capturing,
        CS_Contested,
        CS_Resetting,
        CS_Captured,
        CS_Reset,
        CS_MAX UMETA(Hidden),
    };
}

