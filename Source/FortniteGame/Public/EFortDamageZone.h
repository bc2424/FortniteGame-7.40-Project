#pragma once
#include "CoreMinimal.h"
#include "EFortDamageZone.generated.h"

UENUM(BlueprintType)
namespace EFortDamageZone {
    enum Type {
        Light,
        Normal,
        Critical,
        Vulnerability,
        Max,
    };
}

