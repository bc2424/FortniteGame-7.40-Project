#pragma once
#include "CoreMinimal.h"
#include "FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_TimedModifierTags.generated.h"

USTRUCT(BlueprintType)
struct FFortAIEncounterTimedModifierTags {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float TimeSeconds;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer GameplayTags;
};

UCLASS(Blueprintable)
class UFortDifficultyOptionEncounter_TimedModifierTags : public UFortDifficultyOptionEncounter {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAIEncounterTimedModifierTags> TimedModifierTags;
};

