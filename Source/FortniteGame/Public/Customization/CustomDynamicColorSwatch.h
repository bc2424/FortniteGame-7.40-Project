// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomColorSwatch.h"
#include "CustomDynamicColorSwatch.generated.h"

struct FCustomPartTextureParameter;

USTRUCT(BlueprintType)
struct FColorSwatchPair
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 FName ColorName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 FLinearColor ColorValue;                                      
};

UCLASS(Abstract)
class UCustomDynamicColorSwatch : public UCustomColorSwatch
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color Swatch")
	TArray<FColorSwatchPair> ColorPairs;
/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FCustomPartTextureParameter> TextureParameters;*/
};