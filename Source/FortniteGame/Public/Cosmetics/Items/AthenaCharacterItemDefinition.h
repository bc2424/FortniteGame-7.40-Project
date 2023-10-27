// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Cosmetics/Items/AthenaBackpackItemDefinition.h"
#include "Engine/DataAsset.h"
#include "FortniteGame/Public/STW/Heroes/FortHeroType.h"
#include "AthenaCharacterItemDefinition.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaCharacterItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaCharacterItemDefinition();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HeroType")
	class UFortHeroType* HeroDefinition;

	UPROPERTY(EditAnywhere, Category = "HeroType")
	class UAthenaBackpackItemDefinition* DefaultBackpack;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaCharacter", GetFName());
	}
};
