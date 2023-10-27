// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaSkyDiveContrailItemDefinition.h"
#include "Pawns/FortPlayerPawn.h"
#include "Player/FortPlayerController.h"
#include "FortBodyPartOverridePreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortBodyPartOverridePreviewActor : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	class UAthenaCharacterPartItemDefinition* MyCosmeticItem;
public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewCosmeticItem();
	
	UFUNCTION(BlueprintImplementableEvent)
	void ApplyMyCosmeticItemToHero(class AFortPlayerPawn* PawnToModify, class AFortPlayerController* FortPC);
};
