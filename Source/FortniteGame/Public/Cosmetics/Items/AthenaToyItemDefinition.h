// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AthenaDanceItemDefinition.h"
#include "Abilities/FortGameplayAbility.h"
#include "GameFramework/Actor.h"
#include "Athena/FortToyPreviewActor.h"
#include "AthenaToyItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaToyItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()
protected:
	UAthenaToyItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Visual")
	TSoftClassPtr<UFortGameplayAbility> ToySpawnAbility;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TSoftClassPtr<AActor> ToyActorClass;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TSoftClassPtr<AFortToyPreviewActor> FrontEndPreviewActor;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaVictoryPose", GetFName());
	}
};
