// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAbilityKit.h"
#include "FortniteGame.h"
#include "FortProfileItemDefinition.h"
#include "FortTeamPerkItemDefinition.generated.h"

USTRUCT()
struct FFortTeamPerkLoadoutCondition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int32 NumTimesSatisfiable;
	
	UPROPERTY(EditAnywhere)
	FGameplayTagQuery RequiredTagQuery;

	UPROPERTY(EditAnywhere)
	bool bConsiderMinimumTier;

	UPROPERTY(EditAnywhere)
	bool bConsiderMaximumTier;

	UPROPERTY(EditAnywhere)
	bool bConsiderMinimumLevel;

	UPROPERTY(EditAnywhere)
	bool bConsiderMaximumLevel;

	UPROPERTY(EditAnywhere)
	bool bConsiderMinimumRarity;

	UPROPERTY(EditAnywhere)
	bool bConsiderMaximumRarity;

	UPROPERTY(EditAnywhere)
	EFortItemTier MinimumHeroTier;

	UPROPERTY(EditAnywhere)
	EFortItemTier MaximumHeroTier;

	UPROPERTY(EditAnywhere)
	int32 MinimumHeroLevel;

	UPROPERTY(EditAnywhere)
	int32 MaximumHeroLevel;

	UPROPERTY(EditAnywhere)
	EFortRarity MinimumHeroRarity;

	UPROPERTY(EditAnywhere)
	EFortRarity MaximumHeroRarity;
};

UCLASS()
class FORTNITEGAME_API UFortTeamPerkItemDefinition : public UFortProfileItemDefinition
{
	GENERATED_BODY()
	UFortTeamPerkItemDefinition()
	{
		ItemType = EFortItemType::TeamPerk;
	}
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

	UPROPERTY(EditAnywhere)
	bool bProgressiveBonus;

	UPROPERTY(EditAnywhere)
	FGameplayTagQuery RequiredCommanderTagQuery;

	UPROPERTY(EditAnywhere)
	FText CommanderRequirementsText;

	UPROPERTY(EditAnywhere)
	TArray<FFortTeamPerkLoadoutCondition> TeamPerkLoadoutConditions;
};