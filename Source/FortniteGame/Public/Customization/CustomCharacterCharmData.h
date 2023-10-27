// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterAccessoryData.h"
#include "CustomCharacterCharmData.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterCharmData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Charm")
	EFortCustomPartType  PartAttachedToOverride;
};