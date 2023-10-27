// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaCosmeticItemDefinition.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "GameplayTags.h"
#include "FortniteGame/FortniteGame.h"
#include "FortMontageItemDefinitionBase.generated.h"


USTRUCT()
struct FORTNITEGAME_API FSectionNameAndWeight 
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FName SectionName; 

	UPROPERTY(EditAnywhere)
	float SectionWeight;
};

USTRUCT()
struct FORTNITEGAME_API FMontageVisibilityData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		EMontageVisibilityRule Rule;

	UPROPERTY(EditAnywhere)
		UFortItemDefinition* Item;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortMontageItemDefinitionBase : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Emote")
		TSoftObjectPtr<UAnimMontage> Animation;

	UPROPERTY(EditAnywhere, meta = (AssetBundles = "AvatarDisplay"), Category = "Emote")
		TSoftObjectPtr<UAnimMontage> AnimationFemaleOverride;

	UPROPERTY(EditAnywhere, Category = "Emote")
		int32 PreviewLoops = 1;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float PreviewLength;
	
	UPROPERTY(EditAnywhere, Category = "Emote")
		float EmoteCooldownSecs = 3.0;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMontageContainsFacialAnimation;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bPlayRandomSection;

	UPROPERTY(EditAnywhere, Category = "Emote")
		TArray<FSectionNameAndWeight> PlayRandomSectionByName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Emote")
		bool  bSwitchToHarvestingToolOnUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Emote")
		bool bHolsterWeapon = true;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Emote", GetFName());
	}
};