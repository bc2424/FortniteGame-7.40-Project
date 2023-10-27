// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Animation/FortTaggedSoundBank.h"
#include "FortPlayerPet.h"
#include "FortPetStimuliBank.h"
#include "AthenaPetItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaPetItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaPetItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Visual")
	TArray<UFortPetStimuliBank*> StimuliBanks;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TSoftClassPtr<AFortPlayerPet> PetPrefabClass;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TSoftObjectPtr<UFortTaggedSoundBank> PetSoundBank;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaPetCosmetic", GetFName());
	}
};
