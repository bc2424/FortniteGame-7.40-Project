// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistableItemDefinition.h"
#include "Engine/CurveTable.h"
#include "FortAccountItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortAccountItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Account Item")
	FCurveTableRowHandle LevelToXpHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FCurveTableRowHandle LevelToSacrificeXpHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FDataTableRowHandle SacrificeRecipe;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FDataTableRowHandle TransmogSacrificeRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Conversion")
	TArray<FDataTableRowHandle> ConversionRecipes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Conversion")
	FDataTableRowHandle UpgradeRarityRecipeHandle;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Level")
	int32 MinLevel;                                       

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Level")
	int32 MaxLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString GrantToProfileType;
};