// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Heroes/FortHeroType.h"
#include "FortHeroData.generated.h"

USTRUCT()
struct FHeroPerkDefaultRequirements
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	EFortItemTier MinimumHeroTier;                                  

	UPROPERTY(EditAnywhere)
	int32 MinimumHeroLevel;

	UPROPERTY(EditAnywhere)
	EFortRarity MinimumHeroRarity;
};

USTRUCT()
struct FHeroSubclassRarityAttributeData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TArray<FFortAttributeInitializationKey> AttributeInitKeysPerTier;
};

USTRUCT()
struct FHeroSubclassAttributeData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer HeroClassAndSubclassTags;                        

	UPROPERTY(EditAnywhere)
	TArray<FHeroSubclassRarityAttributeData> AttributeInitKeysPerRarity;
};

USTRUCT()
struct FHeroKeywordDisplayData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FGameplayTag KeyWordGameplayTag;                 

	UPROPERTY(EditAnywhere)
	FText KeywordDisplayName;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortHeroData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Defaults")
	FText DefaultHeroName;

	UPROPERTY(EditAnywhere, Category = "Defaults")
	TSoftObjectPtr<UFortHeroType> DefaultHero;

	UPROPERTY(EditAnywhere, Category = "Defaults")
	FHeroPerkDefaultRequirements CommanderPerkDefaultRequirements;

	UPROPERTY(EditAnywhere, Category = "Defaults")
	bool bTeamPerkDependsOnSupportTierUnlocks = true;

	UPROPERTY(EditAnywhere, Category = "Combined Stats")
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;

	UPROPERTY(EditAnywhere, Category = "Hero Data")
	TArray<FHeroSubclassAttributeData> HeroAttributeDataForSubclasses;

	UPROPERTY(EditAnywhere, Category = "Hero Display Data")
	TArray<FHeroKeywordDisplayData> HeroKeywordDisplayData;

	UPROPERTY(EditAnywhere, Category = "Hero Display Data")
	FText HeroPerkDuplicatedText;

	UPROPERTY(EditAnywhere, Category = "Hero Display Data")
	FText HeroTierTooLowForPerkText;
};