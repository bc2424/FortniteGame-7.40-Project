// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "Styling/SlateBrush.h"

#include "FortTimeOfDayManager.h"

#include "FortWorldSettings.generated.h"

UCLASS()
class FORTNITEGAME_API AFortWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

	AFortWorldSettings();

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FSlateBrush AthenaMapImage;
	UPROPERTY()
	class AFortTimeOfDayManager* TimeOfDayManager;
	UPROPERTY(EditAnywhere, Category = "Time Of Day")
	uint8 bShowTimeOfDayManager : 1;
	UPROPERTY(EditAnywhere, Category = "Time Of Day")
	uint8 bSpawnTimeOfDayManager : 1;
	UPROPERTY(EditAnywhere, Category="Time Of Day")
	class UClass* WorldTimeOfDayManager;
	
	UPROPERTY()
	class UClass* DefaultWorldTimeOfDayManager;

public:
	//~ Begin UObject Interface.
	//virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	//~ End UObject Interface.
};
