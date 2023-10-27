// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariant.h"
#include "Items/FortItemDefinition.h"
#include "FortCosmeticNumericalVariant.generated.h"

UCLASS()
class UFortCosmeticNumericalVariant : public UFortCosmeticVariant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int32 DefaultStartingNumeric;

	UPROPERTY(EditAnywhere)
	int32 MinNumericalValue;

	UPROPERTY(EditAnywhere)
	int32 MaxNumbericalValue;

	UPROPERTY(EditAnywhere)
	FName ZerosDigitParamName;

	UPROPERTY(EditAnywhere)
	FName TensDigitParamName;

	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsToAlter;
};
