// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaMusicPackItemDefinition.h"
#include "FortMusicPackPreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortMusicPackPreviewActor : public AActor
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void PreviewSpray(UAthenaMusicPackItemDefinition* MusicPack);
};
