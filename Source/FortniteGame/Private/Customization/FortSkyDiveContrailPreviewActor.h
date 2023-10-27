// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaSkyDiveContrailItemDefinition.h"
#include "FortSkyDiveContrailPreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortSkyDiveContrailPreviewActor : public AActor
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void PreviewSpray(UAthenaSkyDiveContrailItemDefinition* Contrail);
};
