// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWorldItemDefinition.h"
#include "FortMissionGenerator.h"
#include "FortAmmoItemDefinition.generated.h"

UCLASS()
class UFortAmmoItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
public:
	UFortAmmoItemDefinition();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
	 FSlateBrush ClipIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
	bool bIsConsumed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
	bool bTriggersFeedbackLines;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
	FScalableFloat RegenCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
	FFortMultiSizeBrush AmmoIconBrush;
protected:
	UPROPERTY(EditAnywhere, Category = "Display")
	TSoftObjectPtr<UTexture2D> HUDAmmoSmallPreviewImage;
/*
	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UTexture2D> GetHUDAmmoSmallPreviewImage();*/
};