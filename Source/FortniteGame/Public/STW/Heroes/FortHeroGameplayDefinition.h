//Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "FortAbilityKit.h"
#include "FortHeroClassGameplayDefinition.h"
#include "FortHeroGameplayDefinition.generated.h"

USTRUCT()
struct FORTNITEGAME_API FFortHeroGameplayPiece
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

	UPROPERTY(EditAnywhere)
	FGameplayTagQuery RequiredCommanderTagQuery;

	UPROPERTY(EditAnywhere)
	FText CommanderRequirementsText;

	UPROPERTY(EditAnywhere)
	bool bUseGlobalDefaultMinima;

	UPROPERTY(EditAnywhere)
	EFortItemTier MinimumHeroTier;
	
	UPROPERTY(EditAnywhere)
	int32 MinimumHeroLevel;

	UPROPERTY(EditAnywhere)
	EFortRarity MinimumHeroRarity;
};
USTRUCT()
struct FORTNITEGAME_API FFortHeroTierAbilityKit
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

	UPROPERTY(EditAnywhere)
	EFortRarity MinimumHeroRarity;
};

UCLASS()
class FORTNITEGAME_API UFortHeroGameplayDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Class Data")
	UFortHeroClassGameplayDefinition* HeroClassGameplayDefinition;

	UPROPERTY(EditAnywhere, Category = "Class Data")
	FGameplayTagContainer HeroBaseStatlineTags;

	UPROPERTY(EditAnywhere, Category = "Class Data")
	FGameplayTagContainer HeroTags;

	UPROPERTY(EditAnywhere, Category = "Abilites")
	TArray<FFortHeroTierAbilityKit> TierAbilityKits;

	UPROPERTY(EditAnywhere, Category = "Abilites")
	FFortHeroGameplayPiece HeroPerk;

	UPROPERTY(EditAnywhere, Category = "Abilites")
	FFortHeroGameplayPiece CommanderPerk;
};
