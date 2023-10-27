// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "NiagaraSystem.h"
#include "AthenaSkyDiveContrailItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UAthenaSkyDiveContrailItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UAthenaSkyDiveContrailItemDefinition();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UParticleSystem> ContrailEffect;              

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UNiagaraSystem> NiagaraContrailEffect;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaSkyDiveContrail", GetFName());
	}
};
