#pragma once
#include "CoreMinimal.h"
#include "FortBTDecorator_QueryGameplayAbility.h"
#include "FortBTDecorator_GameplayAbility_DoesTargetHaveProhibitedTags.generated.h"

UCLASS(Blueprintable)
class UFortBTDecorator_GameplayAbility_DoesTargetHaveProhibitedTags : public UFortBTDecorator_QueryGameplayAbility {
    GENERATED_BODY()
public:
    UFortBTDecorator_GameplayAbility_DoesTargetHaveProhibitedTags();
};

