// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Heroes/FortAbilityKit.h"
#include "Pawns/FortPlayerPawn.h"
#include "FortHeroClassGameplayDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortHeroClassGameplayDefinition : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Hero Class")
	TSoftClassPtr<AFortPlayerPawn> OverridePawnClass;

	UPROPERTY(EditAnywhere, Category = "Hero Class")
	FGameplayTagContainer HeroClassTags;

	UPROPERTY(EditAnywhere, Category = "Hero Class")
	FDataTableRowHandle LegacyStatHandle;

	UPROPERTY(EditAnywhere, Category = "Hero Class")
	TArray<TSoftObjectPtr<UFortAbilityKit>> ClassAbilityKits;
};
