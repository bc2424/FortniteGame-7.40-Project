// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortMontageItemDefinitionBase.h"
#include "AthenaVictoryPoseItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaVictoryPoseItemDefinition : public UFortMontageItemDefinitionBase
{
	UAthenaVictoryPoseItemDefinition();
	GENERATED_BODY()
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaVictoryPose", GetFName());
	}
};
