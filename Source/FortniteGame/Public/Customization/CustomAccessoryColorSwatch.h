// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomDynamicColorSwatch.h"
#include "CustomAccessoryColorSwatch.generated.h"


UCLASS()
class UCustomAccessoryColorSwatch : public UCustomDynamicColorSwatch
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Color Swatch")
	FLinearColor AccessoryColors[3];
};