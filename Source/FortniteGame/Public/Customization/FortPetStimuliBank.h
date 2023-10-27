// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomDynamicColorSwatch.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "FortPetStimuliBank.generated.h"

USTRUCT()
struct FORTNITEGAME_API FPetResponseFromQuestSystem
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FDataTableRowHandle ObjectiveStatHandle;

	UPROPERTY(EditAnywhere)
	FGameplayTag ResponseTag;

	UPROPERTY(EditAnywhere)
	float ResponseDuration;
};

UCLASS()
class FORTNITEGAME_API UFortPetStimuliBank : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FPetResponseFromQuestSystem> QuestTriggers;
};