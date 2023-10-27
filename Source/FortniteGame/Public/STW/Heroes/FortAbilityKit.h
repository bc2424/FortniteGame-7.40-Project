// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAbilitySet.h"
#include "Styling/SlateBrush.h"
#include "UI/FortTooltipDisplayStatsList.h"
#include "UI/FortTooltip.h"
#include "FortSchematicItemDefinition.h"
//#include "FortGadgetItemDefinition.h"
#include "FortAbilityKit.generated.h"

USTRUCT()
struct FAbilityKitItem
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere)
    UFortItemDefinition* Item;

    UPROPERTY(EditAnywhere)
    int32 Quantity = 1;

    UPROPERTY(EditAnywhere)
    EFortReplenishmentType Replenishment;
};

UCLASS()
class FORTNITEGAME_API UFortAbilityKit : public UFortAbilitySet
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category = "Display")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category = "Display")
    TArray<FText> Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category = "Display")
    FText TooltipDescription;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
    FSlateBrush IconBrush;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
    FSlateBrush PrimaryTraitIconBrushOverride;
    // circular dependecy I cba to fix
   //UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gadgets")
   //TArray<TSoftObjectPtr<UFortGadgetItemDefinition>> Gadgets;

    UPROPERTY(EditAnywhere, Category = "Items")
    TArray<FAbilityKitItem> Items;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Schematics")
    TArray<UFortSchematicItemDefinition*> AddedSchematics;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Schematics")
    TArray<UFortSchematicItemDefinition*> RemovedSchematics;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ToolTip")
    TSubclassOf<UFortTooltip> Tooltip;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ToolTip")
    TSubclassOf<UFortTooltip> SummaryTooltip;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ToolTips")
    UFortTooltipDisplayStatsList* StatList;
};