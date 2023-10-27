// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CustomAccessoryAttachmentData.generated.h"

UCLASS()
class UCustomAccessoryAttachmentData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Attachment")
	FVector MaleRelativeScale;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	FVector FemaleRelativeScale;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	FVector SmallMaleRelativeScale;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	FVector SmallFemaleRelativeScale;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	FVector LargeMaleRelativeScale;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	FVector LargeFemaleRelativeScale;
};
