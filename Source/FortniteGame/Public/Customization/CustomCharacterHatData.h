// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterAccessoryData.h"
#include "CustomCharacterHatData.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterHatData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Accessory")
	ECustomHatType HatType;
};