// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "Styling/SlateBrush.h"
#include "FortniteGame/FortniteGame.h"
#include "Styling/SlateBrush.h"
#include "AttributeSet.h"
#include "Customization/CustomCharacterPart.h"
#include "FortHeroSpecialization.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FHeroSpecializationAttributeRequirement
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FGameplayAttribute Attribute;    

	UPROPERTY(EditAnywhere)
		float MinimumValue;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortSpecializationSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<FHeroSpecializationAttributeRequirement> AttributeRequirements;

	UPROPERTY(EditAnywhere)
		FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere)
		int MinimumHeroLevel;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortHeroSpecialization : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Specialization Slots")
		TArray<FFortSpecializationSlot> SpecializationSlots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Parts")
		TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterParts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Alteration Definition")
		EFortAlteration AlterationType;

	UPROPERTY(EditAnywhere, Category = "Requirements")
		TArray<FHeroSpecializationAttributeRequirement> AttributeRequirements;

	UPROPERTY(EditAnywhere, Category = "Requirements")
		FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere, Category = "Character Parts")
		bool	bForceShowHeadAccessory;

	UPROPERTY(EditAnywhere, Category = "Character Parts")
		bool	bForceShowBackpack;

	UPROPERTY(EditAnywhere, Category = "Display")
		FSlateBrush CardIconBrush;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("FortHeroSpecialization", GetFName());
	}
};
