// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "AthenaSprayItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaSprayItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaSprayItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Spray")
		TSoftObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(EditAnywhere, Category = "Spray")
		FName ProgressiveCosmeticStatName;

	UPROPERTY(EditAnywhere, Category = "Spray")
		bool bUseBannerAsTexture;
	
	UPROPERTY(EditAnywhere, Category = "Spray")
		TSoftObjectPtr<UTexture2D> DecalTexture;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaDance", GetFName());
	}
};
