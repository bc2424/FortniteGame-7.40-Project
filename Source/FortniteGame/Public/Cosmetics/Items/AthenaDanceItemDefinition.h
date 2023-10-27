// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortMontageItemDefinitionBase.h"
#include "FortniteGame/FortniteGame.h"
#include "AthenaDanceItemDefinition.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaDanceItemDefinition : public UFortMontageItemDefinitionBase
{
	GENERATED_BODY()
public:
	UAthenaDanceItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMovingEmote;
	
	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMoveForwardOnly;
	
	UPROPERTY(EditAnywhere, Category = "Emote")
		float WalkForwardSpeed = 300;
	
	UPROPERTY(EditAnywhere, Category = "Visuals")
		FSoftClassPath CustomDanceAbility;

	UPROPERTY(EditAnywhere, Category = "Emote")
		FText ChatTriggerCommandName;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaDance", GetFName());
	}
};
