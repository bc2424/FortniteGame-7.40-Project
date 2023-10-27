// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Heroes/FortWorkerType.h"
#include "Heroes/FortHeroSpecialization.h"
#include "Animation/FortMontageLookupTable.h"
#include "FrontEnd/FrontendAnimInstance.h"
#include "Abilities/FortGameplayAbility_Structs.h"
#include "FortHeroGameplayDefinition.h"
#include "Sound/FortFeedbackBank.h"
#include "FortHeroType.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortAttributeInitializationKey
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FName AttributeInitCategory;

	UPROPERTY(EditAnywhere)
		FName AttributeInitSubCategory;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortHeroType : public UFortWorkerType
{
	GENERATED_BODY()

public:
	UFortHeroType();
	UPROPERTY(EditAnywhere, Category = "Character Parts")
		bool bForceShowHeadAccessory;

	UPROPERTY(EditAnywhere, Category = "Character Parts")
		bool bForceShowBackpack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AssetBundles = "ItemDetails"), Category = "Specialization")
		TArray<TSoftObjectPtr<UFortHeroSpecialization>> Specializations;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UFortMontageLookupTable> DefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UFortMontageLookupTable> OverrideMontageLookupTable;
	
	UPROPERTY(EditAnywhere, Category = "Combined Stats")
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;
	
	UPROPERTY(EditAnywhere, Category = "Requirements")
		FGameplayTagContainer RequiredGPTags;
	
	UPROPERTY(EditAnywhere, Category = "Feedback")
	TSoftObjectPtr<UFortFeedbackBank> MaleOverrideFeedback;
	
	UPROPERTY(EditAnywhere, Category = "Feedback")
	TSoftObjectPtr<UFortFeedbackBank> FemaleOverrideFeedback;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pawn")
		TSoftClassPtr<AFortPlayerPawn> OverridePawnClass;
	
	UPROPERTY(EditAnywhere)
	UFortHeroGameplayDefinition* HeroGameplayDefinition;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pawn")
		TSoftClassPtr<UFrontendAnimInstance> FrontEndAnimClass;

	UPROPERTY(EditAnywhere, Category = "Pawn")
		TSoftObjectPtr<UAnimMontage> FrontendAnimMontageIdleOverride;

	UPROPERTY(EditAnywhere, Category = "Pawn")
		float FrontEndBackPreviewRotationOffset;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText Subtype;

	UPROPERTY(EditAnywhere, Category = "Attributes")
		FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditAnywhere, Category = "Attributes")
		FDataTableRowHandle LegacyStatHandle;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Hero", GetFName());
	}
};
