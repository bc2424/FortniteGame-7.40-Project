// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaPickaxeItemDefinition.h"
#include "Weapons/FortWeapon.h"
#include "FortPickaxePreviewActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortPickaxePreviewActor : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	 UAnimMontage* MontageToPlayForSwinging;

	UPROPERTY(BlueprintReadOnly)
	 UAthenaPickaxeItemDefinition* CosmeticPickaxeItemDefinition;

	UPROPERTY(BlueprintReadOnly)
	 AFortWeapon* WeaponActor;
	
	UPROPERTY(BlueprintReadOnly)
	 AFortWeapon* WeaponActor2;
	
	UFUNCTION(BlueprintImplementableEvent)
	void PreviewPickaxeVariantsApplied(class UAthenaPickaxeItemDefinition* Pickaxe);
};