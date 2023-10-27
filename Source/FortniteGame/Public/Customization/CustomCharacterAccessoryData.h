// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterPartData.h"
#include "CustomAccessoryColorSwatch.h"
#include "CustomAccessoryAttachmentData.h"
#include "CustomCharacterAccessoryData.generated.h"

class UAnimInstance;

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterAccessoryData : public UCustomCharacterPartData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
	FName AttachSocketName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
	UCustomAccessoryAttachmentData* AttachmentOverrideData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
	bool bUseClothCollisionFromOtherParts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
	bool bCollideWithOtherPartsCloth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditAnywhere, Category = "Accessory")
	TSoftClassPtr<UAnimInstance> FrontEndAnimClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
	TSoftClassPtr<UAnimInstance> MannequinAnimClass;

	UPROPERTY(EditAnywhere, Category = "Accessory")
	TSoftObjectPtr<UCustomAccessoryColorSwatch> AccessoryColors;
};