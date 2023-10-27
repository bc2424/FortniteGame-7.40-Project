// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItem.h"
#include "FortAbilityKit.h"
#include "FortHeroSpecialization.h"
#include "CustomCharacterPart.h"
#include "FortHero.generated.h"

UCLASS()
class FORTNITEGAME_API UFortHero : public UFortAccountItem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FString Hero_name;

//	UPROPERTY()
//	TArray<FFortSavedModeLoadout> Mode_loadouts;

	UPROPERTY()
	bool Refundable;

	UPROPERTY()
	TArray<UFortHeroSpecialization*> Specializations;

	UPROPERTY()
	TArray<UFortAbilityKit*> SpecializationAbilityKits;
	
	UPROPERTY()
	TArray<UCustomCharacterPart*> CharacterParts;
};
