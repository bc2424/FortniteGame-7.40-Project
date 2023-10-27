// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPickup.h"
#include "FortInventory.h"
#include "FortWorldItem.generated.h"


UCLASS()
class FORTNITEGAME_API UFortWorldItem : public UFortItem
{
	GENERATED_BODY()
public:
	UPROPERTY()
	bool bIsTemporaryItem;

	UPROPERTY()
	bool bNeedsPersistentUpdate;

	UPROPERTY()
	bool bPendingPersistentDelete;

	UPROPERTY()
	AFortInventory* OwnerInventory;

	UPROPERTY()
	FFortItemEntry ItemEntry;
};