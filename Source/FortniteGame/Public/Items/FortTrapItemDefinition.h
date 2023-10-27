// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDecoItemDefinition.h"
#include "FortTrapItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortTrapItemDefinition : public UFortDecoItemDefinition
{
	GENERATED_BODY()

public:
	UFortTrapItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Trap")
	FRotator KnockbackDirOverride; 

	UPROPERTY(EditAnywhere, Category = "Trap")
	bool bKnockBackUsingPawnDir; 

	UPROPERTY(EditAnywhere, Category = "Sounds")
	TSoftObjectPtr<USoundBase> EquipSound;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Trap", GetFName());
	}
};
