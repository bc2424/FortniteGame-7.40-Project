// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaBackpackItemDefinition.h"
#include "Items/AthenaPickaxeItemDefinition.h"
#include "FortPlayerPet.h"
#include "AthenaPetCarrierItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaPetCarrierItemDefinition : public UAthenaBackpackItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Visuals")
	UAthenaPetItemDefinition* DefaultPet;  

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
	FFortUICameraFrameTargetBounds CameraFramingBounds;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaBackpack", GetFName());
	}
};
