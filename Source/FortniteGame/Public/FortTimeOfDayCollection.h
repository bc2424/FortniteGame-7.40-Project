// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTimeOfDayManager.h"
#include "FortTimeOfDayCollection.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FORTNITEGAME_API UFortTimeOfDayCollection : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TArray<TSoftClassPtr<AFortTimeOfDayManager>> TimeOfDayManagers; 
};
