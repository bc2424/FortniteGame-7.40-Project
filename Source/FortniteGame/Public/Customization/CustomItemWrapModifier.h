// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CustomCosmeticModifierBase.h"
#include "Athena/DrivableVehicles/FortAthenaVehicle.h"
#include "CustomItemWrapModifier.generated.h"

UCLASS()
class FORTNITEGAME_API ACustomItemWrapModifier : public ACustomCosmeticModifierBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortAthenaVehicle> VehiclePtr;
/*
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> WeaponPtr;*/
};