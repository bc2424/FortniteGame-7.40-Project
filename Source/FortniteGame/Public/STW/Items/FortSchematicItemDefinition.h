// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAlterableItemDefinition.h"
#include "FortSchematicItemDefinition.generated.h"

UCLASS()
class UFortSchematicItemDefinition : public UFortAlterableItemDefinition
{
	GENERATED_BODY()
public:
	UFortSchematicItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Crafting")
	FDataTableRowHandle CraftingRecipe;

	UPROPERTY(EditAnywhere, Category = "Crafting")
	TSoftObjectPtr<USoundBase> CraftingSuccessSound;

	UPROPERTY(EditAnywhere, Category = "Loot Level")
	FDataTableCategoryHandle LootLevelData;

	UPROPERTY(EditAnywhere, Category = "Crafting")
	FName CraftingTimeRowName = "Craft_Tier_1";

	UPROPERTY(EditAnywhere, Category = "Display")
	bool bUseSchematicDisplayName;
};