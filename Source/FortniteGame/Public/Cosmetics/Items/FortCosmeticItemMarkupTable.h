// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortCosmeticItemMarkupTable.generated.h"

UCLASS()
class FORTNITEGAME_API UFortCosmeticItemMarkupTable : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UDataTable*> SetDescriptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UDataTable*> MarkupTagDescriptions;
};
