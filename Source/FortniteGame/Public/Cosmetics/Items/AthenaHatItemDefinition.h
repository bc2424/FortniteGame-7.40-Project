// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaCharacterPartItemDefinition.h"
#include "AthenaHatItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaHatItemDefinition : public UAthenaCharacterPartItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaHatItemDefinition();
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaHat", GetFName());
	}
};
