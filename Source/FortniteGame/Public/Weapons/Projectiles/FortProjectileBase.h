// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayEffectDeliveryActor.h"
#include "Engine/CurveTable.h"
#include "Components/CapsuleComponent.h"
#include "Projectiles/FortProjectileMovementComponent.h"
#include "FortniteGame.h"
#include "AttributeSet.h"
#include "FortProjectileBase.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortProjectileBase : public AFortGameplayEffectDeliveryActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	AFortProjectileBase();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FScalableFloat ProjectileGravityScale;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FCurveTableRowHandle VerticleFireOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FCurveTableRowHandle InitialSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FCurveTableRowHandle MaxSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float ReplicatedMaxSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float ChargePercent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MomentumTransfer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAddOwnerVelocity = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bSpawnPointCanBeUsedByOtherPlayers;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float PlayerSpawnOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bCanBePickedUpWhenStopped;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bDummyProjectile;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bStopSimulatingOnHit;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bDisableCollisionOnStop;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bStoppedSimulatingDueToHit;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bReplicateStopSimulationLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bClientInterpMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bClientInterpRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAutoSelectAttachedForInterp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FHitResult SimulationStoppingHit;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bFiredWhileTargeting;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 ResumeSimulationCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TEnumAsByte<EFortBaseWeaponDamage::Type> WeaponResponseType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FGameplayTagContainer DefaultTags;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USceneComponent* CachedPassByPawn;

	UFUNCTION(BlueprintImplementableEvent)
		void OnStoppedOnServer();

	UFUNCTION(BlueprintImplementableEvent)
		void OnStopCallback(FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
		void OnStop(FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
		void OnShot(FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
		void OnResumeSimulation();
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnRep_SimulationStoppingHit();
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnRep_ResumeSimulationCount();
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnRep_ReplicatedMaxSpeed();
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnRep_GravityScale();

	UFUNCTION(BlueprintImplementableEvent)
		void OnBounceCallback(FHitResult& Hit, FVector& ImpactVelocity);
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnBounce(FHitResult& Hit);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UCapsuleComponent* CapsuleComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UFortProjectileMovementComponent* ProjectileMovementComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};