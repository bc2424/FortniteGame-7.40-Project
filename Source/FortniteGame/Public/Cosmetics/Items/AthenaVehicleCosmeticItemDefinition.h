// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortMontageItemDefinitionBase.h"
#include "FortniteGame.h"
#include "AthenaVehicleCosmeticItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaVehicleCosmeticItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaVehicleCosmeticItemDefinition();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EFortVehicleDecoType DecoType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransform DecoSocketTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> TestDecoMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DecoSocketName;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaVehicleCosmetic", GetFName());
	}
};
