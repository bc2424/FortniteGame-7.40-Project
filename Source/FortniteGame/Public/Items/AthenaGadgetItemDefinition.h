// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortGadgetItemDefinition.h"
#include "AthenaGadgetItemDefinition.generated.h"

UCLASS()
class UAthenaGadgetItemDefinition : public UFortGadgetItemDefinition
{
	GENERATED_BODY()

public:
	UAthenaGadgetItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Inventory")
	bool bCanBeDroppedWhenEquipmentChangeIsBlocked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	bool bAllowedFuelGadgetUI = true; 
	
};


