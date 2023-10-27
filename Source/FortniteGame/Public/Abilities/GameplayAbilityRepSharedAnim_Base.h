#pragma once
#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "GameplayAbilityRepSharedAnim_Base.generated.h"

USTRUCT(BlueprintType)
struct FGameplayAbilityRepSharedAnim_Base {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortSharedAnimationState AnimState;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 MontageSectionToPlay;
};

USTRUCT(BlueprintType)
struct FGameplayAbilityRepSharedAnim_Index : public FGameplayAbilityRepSharedAnim_Base {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 MontageIndex;
};

USTRUCT(BlueprintType)
struct FGameplayAbilityRepSharedAnim : public FGameplayAbilityRepSharedAnim_Base {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UAnimMontage* AnimMontage;
};

