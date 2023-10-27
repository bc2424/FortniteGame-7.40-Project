// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "AI/HotSpots/AIHotSpotConfig.h"
#include "AI/HotSpots/BuildingActorHotSpotConfig.h"
#include "BuildingEditModeMetadata.generated.h"

UCLASS()
class UBuildingEditModeMetadata : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bSupportNextPieceAssist;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bHasNavigableOpening;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bHasCustomAttackLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 UBuildingActorHotSpotConfig* DefaultHotspotConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 UAIHotSpotConfig* ShootingHotSpotConfig;
protected:
	UPROPERTY()
	 FConnectivityCube ConnectivityCubeData;

};
