// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "BuildingActorHotSpotConfig.generated.h"

UCLASS()
class UBuildingActorHotSpotConfig : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	FBuildingActorHotSpotDirection DirectionSetup[6];

	UPROPERTY(EditAnywhere)
	FBuildingActorHotSpotDirection DefaultSetup;

	UPROPERTY(EditAnywhere)
	UAIHotSpotConfig* ExtraTypeConfig;

	UPROPERTY(EditAnywhere)
	bool bHasDirectionalSetup;
};