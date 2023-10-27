// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "AthenaCosmeticItemDefinition.generated.h"

class UAthenaCharacterItemDefinition;
class UFortMontageItemDefinitionBase;
class UAthenaCosmeticItemDefinition;

USTRUCT(BlueprintType)
struct FFortStatManagerTag : public FGameplayTag
{
	GENERATED_BODY()
public:
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FMcpVariantChannelInfo
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTagContainer OwnedVariantTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UFortItemDefinition* ItemVariantIsUsedFor;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortCosmeticVariantPreviewElement
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FMcpVariantChannelInfo> VariantOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAthenaCosmeticItemDefinition* Item;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FortCosmeticVariantPreview
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText UnlockCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PreviewTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FMcpVariantChannelInfo> VariantOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FFortCosmeticVariantPreviewElement> AdditionalItems;
};

USTRUCT(BlueprintType)
struct FAthenaCosmeticMaterialOverride
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int MaterialOverrideIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

USTRUCT(BlueprintType)
struct FCosmeticVariantInfo
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag ActiveVariantTag;
};


USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPair 
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FFortStatManagerTag StatTag;

	UPROPERTY(EditAnywhere)
	int32 StatValue; 
};

USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPreview
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FText UnlockCondition;

	UPROPERTY(EditAnywhere)
	TArray<FFortCosmeticAdaptiveStatPair> StatValues; 
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaCosmeticItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
	bool bIsShuffleTile;
	
	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		FRotator PreviewPawnRotationOffset;
	
	UPROPERTY(EditAnywhere, Category = "Display")
		FGameplayTagContainer DisallowedCosmeticTags;
	
	UPROPERTY(EditAnywhere, Category = "Visual|Overrides")
		TArray<FAthenaCosmeticMaterialOverride> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category = "Visual|Overrides")
		FGameplayTagContainer ObservedPlayerStats;

   UPROPERTY(EditAnywhere, Category = "Visual|Overrides")
	TArray<UFortMontageItemDefinitionBase*> BuiltInEmotes;
	
	UPROPERTY(EditAnywhere, Instanced, Category = "Variants")
		TArray<UFortCosmeticVariant*> ItemVariants;

	UPROPERTY(EditAnywhere, Category = "Variants")
		FGameplayTag VariantChannelToUseForThumbnails;

	UPROPERTY(EditAnywhere, Category = "Variants")
		TArray<FortCosmeticVariantPreview> ItemVariantPreviews;

	UPROPERTY(EditAnywhere, Category = "Variants")
		FText DirectAquisitionStyleDisclaimerOverride;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TArray<FFortCosmeticAdaptiveStatPreview> ItemObservedStatPreviews;
	
};
