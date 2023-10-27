// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortAccountItemDefinition.h"
#include "FortHomebaseBannerIconItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortHomebaseBannerIconItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()
	UFortHomebaseBannerIconItemDefinition();
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("HomebaseBannerIcon", GetFName());
	}
};
