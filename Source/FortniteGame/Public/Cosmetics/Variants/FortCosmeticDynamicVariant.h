// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariantTypes.h"
#include "FortCosmeticVariant.h"
#include "FortCosmeticDynamicVariant.generated.h"

USTRUCT()
struct FDynamicVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<UVariantTypeBase*> DynamicVariants;
};

UCLASS()
class UFortCosmeticDynamicVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
	TArray<FDynamicVariantDef> DynamicOptions;                                   
};