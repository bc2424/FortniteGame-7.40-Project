// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AttributeSet.h"
#include "FortTooltipDisplayStatsList.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FFortTooltipDisplayStatInfo
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		FGameplayTag Token;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		FGameplayAttribute Attribute;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		FGameplayTagContainer ContextTags;

};


USTRUCT(BlueprintType)
struct FFortTooltipDisplayStatsCategory
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		FText CategoryName;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TArray<FFortTooltipDisplayStatInfo> TooltipStats;
};


UCLASS(BlueprintType)
class FORTNITEGAME_API UFortTooltipDisplayStatsList : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TArray<FFortTooltipDisplayStatsCategory> TooltipCategories;

};
