// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariant.h"
#include "FortCosmeticVariantTypes.h"
#include "FortCosmeticMaterialVariant.generated.h"

USTRUCT()
struct FORTNITEGAME_API FMaterialVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMaterialVariants> VariantMaterials;
};

UCLASS()
class UFortCosmeticMaterialVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
	TArray<FMaterialVariantDef> MaterialOptions;
};