// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortItem.generated.h"

UCLASS()
class UFortItemIconDefinition : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> SmallImage;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> LargeImage;
};
UCLASS()
class FORTNITEGAME_API UFortItem : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	bool bLoadedFromSave;

	UPROPERTY(EditAnywhere)
	bool bTemporaryItemOwningController;
};
