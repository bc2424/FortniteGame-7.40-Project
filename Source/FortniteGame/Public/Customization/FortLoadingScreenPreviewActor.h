// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaLoadingScreenItemDefinition.h"
#include "FortLoadingScreenPreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortLoadingScreenPreviewActor : public AActor
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void PreviewLoadingScreen(UAthenaLoadingScreenItemDefinition* LoadingScreen);
};