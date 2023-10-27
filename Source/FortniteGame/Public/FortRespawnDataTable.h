// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortRespawnDataTable.generated.h"

UCLASS()
class FORTNITEGAME_API UFortRespawnDataTable : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* RespawnData;
};
