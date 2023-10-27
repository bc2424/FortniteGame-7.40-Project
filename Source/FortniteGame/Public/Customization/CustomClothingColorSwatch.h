// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CustomColorSwatch.h"
#include "CustomClothingColorSwatch.generated.h"

UCLASS()
class UCustomClothingColorSwatch : public UCustomColorSwatch
{
	GENERATED_BODY()
	UCustomClothingColorSwatch();
protected:
	UPROPERTY(EditAnywhere, Category = "Color Swatch")
	 FLinearColor AccessoryColors[2];
};