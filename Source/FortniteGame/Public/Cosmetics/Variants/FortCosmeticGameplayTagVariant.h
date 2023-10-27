// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariant.h"
#include "Items/FortItemDefinition.h"
#include "FortCosmeticGameplayTagVariant.generated.h"

USTRUCT()
struct FGameplayTagVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()
public:
};

UCLASS()
class UFortCosmeticGameplayTagVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
	TArray<FGameplayTagVariantDef> GenericTagOptions;
};