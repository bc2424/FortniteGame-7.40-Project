// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GamePlayTags.h"
#include "FortDeathCauseData.generated.h"

USTRUCT()
struct FFortDeathCauseInfoVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	FString DisplayText;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	FGameplayTag DeathCauseTag;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> SelfInflictedMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> SelfInflictedDBNOMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> EliminatedMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> EliminatedDBNOMessages;
};

USTRUCT()
struct FFortDeathCauseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	 FString DisplayText;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	 FGameplayTag DeathCauseTag;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> SelfInflictedMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> SelfInflictedDBNOMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> EliminatedMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FText> EliminatedDBNOMessages;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
	TArray<FFortDeathCauseInfoVariant> DeathCauseInfoVariants;
};


UCLASS()
class UFortDeathCauseData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Death Cause", meta = (IgnoreForMemberInitializationTest))
	TArray<FFortDeathCauseInfo> DeathCauseInfos; 
};
