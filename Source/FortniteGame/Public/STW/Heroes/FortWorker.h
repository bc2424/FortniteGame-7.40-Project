// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCharacter.h"
#include "FortAccountItemDefinition.h"
#include "FortItem.h"
#include "FortWorker.generated.h"

UCLASS()
class FORTNITEGAME_API UFortWorker : public UFortCharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FString Slotted_building_id;

	UPROPERTY(BlueprintReadOnly)
	int32 building_slot_used;

	UPROPERTY(BlueprintReadOnly)
	int32 Gender;

	UPROPERTY(BlueprintReadOnly)
	FString Personality;

	UPROPERTY(BlueprintReadOnly)
	FString Set_bonus;

	UPROPERTY(BlueprintReadOnly)
	FString Portrait;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer PersonalityTag;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer SetBonusTag;

	UPROPERTY(EditAnywhere, Transient)
	TSoftObjectPtr<UFortItemIconDefinition> IconDefinition;
};