// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponItemDefinition.h"
#include "Building/EditMode/BuildingEditModeMetadata.h"
#include "FortBuildingItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortBuildingItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()
public:
	UFortBuildingItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Building Meta Data")
	TSoftObjectPtr<UBuildingEditModeMetadata> BuildingMetaData;
};