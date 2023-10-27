// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Engine/DataAsset.h"
#include "CustomColorSwatch.generated.h"

UCLASS(Abstract)
class UCustomColorSwatch : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color Swatch")
	EFortCustomGender GenderPermitted;

	UPROPERTY(AssetRegistrySearchable)
	EColorSwatchType ColorSwatchType;
};
