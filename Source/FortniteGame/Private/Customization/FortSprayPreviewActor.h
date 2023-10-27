// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaSprayItemDefinition.h"
#include "FortSprayPreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortSprayPreviewActor : public AActor
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void PreviewSpray(UAthenaSprayItemDefinition* Spray);
};
