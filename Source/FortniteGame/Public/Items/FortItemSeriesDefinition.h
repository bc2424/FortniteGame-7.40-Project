// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "FortItemSeriesDefinition.generated.h"

UCLASS(BlueprintType)
class UFortItemSeriesDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText DisplayName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortColorPalette Colors;
};
