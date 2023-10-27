// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "Abilities/FortAbilitySet.h"
#include "FortCosmeticModification.h"
#include "FortAlterationItemDefinition.generated.h"

USTRUCT(BlueprintType)
struct FFortConditionalCosmeticModification
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FFortCosmeticModification                   CosmeticModification;                                     // 0x0000(0x08F8) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer                       ConditionalTags;                                          // 0x08F8(0x0020) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly)
};

USTRUCT(BlueprintType)
struct FFortConditionalIncludeTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FGameplayTagContainer ConditionTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FGameplayTagContainer  IncludeTags;                                          
};
UCLASS(BlueprintType)
class FORTNITEGAME_API UFortAlterationItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFortAlterationItemDefinition();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alteration Definition")
	TEnumAsByte<EFortAlteration> AlterationType;

	UPROPERTY(EditAnywhere, Category = "Alteration Cosmetic")
	FFortCosmeticModification DefaultCosmetic;

	UPROPERTY(EditAnywhere, Category = "Alteration Cosmetic")
	TArray<FFortConditionalCosmeticModification> ConditionalCosmetics;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alteration Gameplay")
	TArray<FFortConditionalIncludeTags> AdditionalGameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alteration Gameplay")
	TSoftObjectPtr<UFortAbilitySet> AlterationAbilitySet;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Alteration", GetFName());
	}
};
