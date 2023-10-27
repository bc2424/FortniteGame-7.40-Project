// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Customization/FortMapMarkerTopperActor.h"
#include "AthenaMapMarkerItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UAthenaMapMarkerItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaMapMarkerItemDefinition();
	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AFortMapMarkerTopperActor> TopperActorClass;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaMapMarker", GetFName());
	}
};
