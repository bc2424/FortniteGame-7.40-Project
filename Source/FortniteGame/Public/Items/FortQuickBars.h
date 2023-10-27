// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClientOnlyActor.h"
#include "FortWorldItemDefinition.h"
#include "FortniteGame.h"
#include "FortItemDefinition.h"
#include "FortWorldItem.h"
#include "FortQuickBars.generated.h"

USTRUCT()
struct FQuickBarSlot
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TArray<FGuid> Items;

	UPROPERTY(Transient)
	bool bEnabled;
};

USTRUCT()
struct FQuickBarSlotData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<EFortItemType>  AcceptedItemTypes;

	UPROPERTY(EditAnywhere)
	bool bStaticSlot;                                     

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortWorldItemDefinition> DefaultItem;                                      
};

USTRUCT()
struct FQuickBarData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FQuickBarSlotData> QuickbarSlots;
};

USTRUCT()
struct FQuickBar
{
	GENERATED_BODY()
public:
	UPROPERTY(Transient)
	int32 CurrentFocusedSlot; 

	UPROPERTY(Transient)
	int32 PreviousFocusedSlot;

	UPROPERTY(Transient)
	int32 SecondaryFocusedSlot; 
	
	UPROPERTY()
	TArray<FQuickBarSlot> Slots;

	UPROPERTY(Transient)
	FQuickBarData DataDefinition;

	UPROPERTY(Transient)
	TSet<UFortItemDefinition*> EquippedItemDefinitions; 

	UPROPERTY(Transient)
	TArray<int32> SharedVisibleSlotIndicesWhenUsingGamepad;
};

UCLASS()
class FORTNITEGAME_API AFortQuickBars : public AFortClientOnlyActor
{
	GENERATED_BODY()

	UPROPERTY()
	FQuickBar PrimaryQuickBar;
	
	UPROPERTY()
	FQuickBar SecondaryQuickBar;

	UPROPERTY()
	FQuickBar CreativeQuickBar;

	UPROPERTY()
	TArray<UFortWorldItem*> AllCachedTraps;

	UPROPERTY()
	TArray<UFortWorldItem*> CachedFloorTraps;

	UPROPERTY()
	TArray<UFortWorldItem*> CachedWallTraps;

	UPROPERTY()
	TArray<UFortWorldItem*> CachedCeilingTraps;
};
