#pragma once
#include "CoreMinimal.h"
#include "EFortPvPGameResult.generated.h"

UENUM(BlueprintType)
namespace EFortPvPGameResult {
    enum Type {
        Win,
        Loss,
        Draw,
    };
}

