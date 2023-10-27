// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWorldItemDefinition.h"
#include "Items/FortItemDefinition.h"
#include "FortBackpackItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortBackpackItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
	UFortBackpackItemDefinition()
	{
		ItemType = EFortItemType::BackpackPickup;
		OwnerPickupText = NSLOCTEXT("BackpackItemDef", "BackpackOwnerName", "Pack");
	}
};
