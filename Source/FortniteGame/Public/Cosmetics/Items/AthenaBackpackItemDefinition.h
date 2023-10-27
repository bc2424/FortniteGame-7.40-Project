// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCharacterPartItemDefinition.h"
#include "AthenaBackpackItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UAthenaBackpackItemDefinition : public UAthenaCharacterPartItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaBackpackItemDefinition();
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaBackpack", GetFName());
	}
};
