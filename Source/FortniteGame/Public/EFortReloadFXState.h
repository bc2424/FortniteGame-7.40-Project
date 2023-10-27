#pragma once
#include "CoreMinimal.h"
#include "EFortReloadFXState.generated.h"

UENUM(BlueprintType)
namespace EFortReloadFXState {
    enum Type {
        ReloadStart,
        ReloadCartridge,
        ReloadEnd,
        Max_None,
    };
}

