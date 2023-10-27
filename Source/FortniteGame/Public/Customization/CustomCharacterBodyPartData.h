// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterAccessoryData.h"
#include "CustomCharacterBodyPartData.generated.h"

class UAnimInstance;

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterBodyPartData : public UCustomCharacterPartData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Body")
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditAnywhere, Category = "Body")
	TSoftClassPtr<UAnimInstance> FrontEndAnimClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Body")
	TSoftClassPtr<UAnimInstance> MannequinAnimClass;

	UPROPERTY(EditAnywhere, Category = "Body")
	TSoftObjectPtr<UCustomAccessoryColorSwatch> AccessoryColors;

};