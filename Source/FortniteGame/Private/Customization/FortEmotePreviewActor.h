// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/FortMontageItemDefinitionBase.h"
#include "FortEmotePreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortEmotePreviewActor : public AActor
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent)
	void PreviewEmote(class UFortMontageItemDefinitionBase* Emote);
};
