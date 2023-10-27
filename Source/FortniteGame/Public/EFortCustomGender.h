#pragma once
#include "CoreMinimal.h"
#include "EFortCustomGender.generated.h"

UENUM(BlueprintType)
namespace EFortCustomGender {
    enum Type {
        Invalid,
        Male,
        Female,
        Both,
    };
}

