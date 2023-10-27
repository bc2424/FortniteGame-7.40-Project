// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWorldItemDefinition.h"
#include "Items/FortItemDefinition.h"
#include "FortQuestItemDefinition.h"
#include "FortPackPersonality.h"
#include "FortCardPackItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortCardPackItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
	UFortCardPackItemDefinition()
	{
		ItemType = EFortItemType::CardPack;
	}
	UPROPERTY(EditAnywhere, AssetRegistrySearchable)
	bool bIsLlama;;

	UPROPERTY(EditAnywhere)
	bool bIsChoicePack;

	UPROPERTY(EditAnywhere)
	bool bAutoOpenAsReward = true;

	UPROPERTY(EditAnywhere)
	int32 LootTier;

	UPROPERTY(EditAnywhere)
	FString LootTierGroup;
	
	UPROPERTY(EditAnywhere)
	int32 DisplayRarityLevel;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture> PackImage;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> XRayTexture;

	UPROPERTY(EditAnywhere)
	FLinearColor PackColor;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortPackPersonality> PackPersonality; 
};
