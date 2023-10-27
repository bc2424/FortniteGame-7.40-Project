// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortMontageItemDefinitionBase.h"
#include "FortEmoteItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortEmoteItemDefinition : public UFortMontageItemDefinitionBase
{
	GENERATED_BODY()
public:
	UFortEmoteItemDefinition();
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Emote")
	FText CommandName;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Emote", GetFName());
	}
};
