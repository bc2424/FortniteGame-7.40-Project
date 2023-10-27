// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortMontageItemDefinitionBase.h"
#include "FortniteGame/FortniteGame.h"
#include "AthenaConsumableEmoteItemDefinition.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaConsumableEmoteItemDefinition : public UFortMontageItemDefinitionBase
{
	GENERATED_BODY()

	UAthenaConsumableEmoteItemDefinition();
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaConsumableEmote", GetFName());
	}
};
