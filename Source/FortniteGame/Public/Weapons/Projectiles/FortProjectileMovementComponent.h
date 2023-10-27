// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "FortniteGame.h"
#include "FortPawn.h"
#include "FortProjectileMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortProjectileMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EFortHomingStyle InitialHomingStyle;

	UPROPERTY(Transient, BlueprintReadWrite)
		float HomingLaserTargetDistance;

	UPROPERTY(Transient, BlueprintReadWrite)
		bool bHasHomedTowardTarget;
	
	UPROPERTY(Transient, BlueprintReadWrite)
		float HomingTravelTime;

	UPROPERTY(Transient, BlueprintReadWrite)
		TWeakObjectPtr<AFortPawn> LockedOnTarget;

	UPROPERTY(Transient, BlueprintReadWrite)
		FVector DesiredDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AccelerationMagnitude;

};