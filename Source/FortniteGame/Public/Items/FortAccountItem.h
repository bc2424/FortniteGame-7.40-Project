// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistableItem.h"
#include "FortAccountItem.generated.h"

UCLASS()
class UFortAccountItem : public UFortPersistableItem
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int32 Level;

	UPROPERTY(EditAnywhere)
	int32 Xp;

	UPROPERTY(EditAnywhere)
	int32 Item_seen;

	UPROPERTY(EditAnywhere)
	int32 Favorite;

	UPROPERTY(EditAnywhere)
	int32 Max_level_bonus;
	
	UPROPERTY(EditAnywhere)
	FString Inventory_overflow_date;

	UPROPERTY(EditAnywhere)
	bool bIsPendingBeingMarkedAsSeen;

	UPROPERTY(EditAnywhere)
	bool bNeedsResolveMarkedAsSeen;
};
