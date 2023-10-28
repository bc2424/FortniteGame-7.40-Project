#pragma once
#include "CoreMinimal.h"
#include "EGameplayModOp.h"
#include "GameplayAttribute.h"
#include "GameplayTagRequirements.h"
#include "FortAttributeModifierDisplayData.generated.h"

USTRUCT(BlueprintType)
struct FFortAttributeModifierDisplayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayAttribute Attribute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EGameplayModOp::Type> ModifierType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagRequirements SourceTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagRequirements TargetTags;
    
    FORTNITEUI_API FFortAttributeModifierDisplayData();
};

