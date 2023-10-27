// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "FortProjectileBase.h"
#include "FortProjectileAthena.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortProjectileAthena : public AFortProjectileBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector_NetQuantize FireStartLoc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FHitResult PawnHitResult;

};
