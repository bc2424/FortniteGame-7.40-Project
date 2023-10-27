// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayAbilitySpec.h"
#include "Math/Color.h"
#include "FortniteGame.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "Weapons/FortWeapon.h"
#include "FortWeaponRanged.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API AFortWeaponRanged : public AFortWeapon
{
	GENERATED_BODY()

private:
	/* Config */
	UPROPERTY(config)
		bool bUseAthenaRecoil;

	UPROPERTY(config)
		bool bUseAthenaPerfectADSAim;
	
	UPROPERTY(config)
		bool bFirstShotAccuracyCheckVehicleMovement;
	
	UPROPERTY(config)
		bool FirstShotAccuracyMinWaitTime;

	// i have NO IDEA what this does
	UPROPERTY(config)
		bool bAllowAutomaticWeaponCatchup;

	UPROPERTY(config)
		bool bEnableRecoilDelay;

public:
	/* Effects */
	// Choose a tracer for this weapon
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		UClass* TracerTemplate;

	// Specifies if the weapon uses tracer meshes or not, default is true
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bUseTracers = true;

	// Muzzle Particles used when the weapon fires
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		UParticleSystem* MuzzleParticleSystem;

	// Muzzle Particles used when the weapon fires and first person view is enabled (i think)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		UParticleSystem* MuzzleParticleSystem1P;

	// Specify which beam particles to use
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		UParticleSystem* BeamParticleSystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		UParticleSystemComponent* BeamPSC;

	// When true, weapon uses persistent (looped) muzzle effects
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bPersistentFireFX;

	// When true, weapon uses persistent (looped) beam effects
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bUsePersistentBeam;

	// Socket that the beam particles spawn on
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Effects")
		FName BeamSourceSocketName;

	// When true, weapon uses beam particles (creates a trail behind a projectile or tracer)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bUseBeamParticles;

	// When true, weapon uses impact effects if the weapon is projectile-based rather than hitscan.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bUseImpactFXForProjectiles;

	// When true, weapon uses impact effects if the weapon is projectile-based rather than hitscan and the projectile overlaps.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bUseImpactFXForProjectileOverlaps;

	// When true, the weapon ejects shell casings 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bUseShellsParticles;

	/* Distance Effect Quality */
	// Controls effect quality for beam effects
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects Quality")
		FFortEffectDistanceQuality BeamSignificance;

	// Controls effect quality for impact effects
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects Quality")
		FFortEffectDistanceQuality ImpactSignificance;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects Quality")
		float ScopeImpactEffectDistanceOffset;

	/* Weapon Data */
	// When true, weapon fire traces start at the muzzle 
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		bool bShouldAimFromMuzzle;

	// When true, weapon fire traces start at the muzzle at close range (fixes ghost peeking)
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Data")
		bool bShouldAimFromMuzzleAtCloseRange;

	UPROPERTY(Transient, BlueprintReadWrite, VisibleAnywhere, Category = "Weapon Data|Runtime", meta = (DisplayName = "Current Number of Bullets"))
		int32 CurrentNumBullets;

	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, Category = "Weapon Data|Runtime")
		int ShellReloadCounter;

	// Location of muzzle blockage, not sure if this is relative to the weapon or in world space
	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, Category = "Weapon Data|Runtime")
		FVector CurrentMuzzleBlockedLocation;

	// The location of where the current damage started
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		EFortAbilityTargetingSource CurrentDamageStart;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Misc")
		FRotator MaxTargetingAimAdjustment;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Misc")
		float ProjectilePitchOffset;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Misc")
		FRotator TargetingRotAdjustmentTotal;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Misc")
		float LastTargetingRotAdjustmentWeight;

	/* Overheating Data */
	// Unsure what this does
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Data|Overheat")
		bool bCooldownWhileOverheated;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon Data|Overheat")
		float OverheatValue;

	// How long ago heat was last added to the weapon
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Overheat|Runtime")
		float TimeHeatWasLastAdded;

	// How long ago since current overheat started
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Overheat|Runtime")
		float TimeOverheatedBegan;

	// What state of overheating this weapon is currently in
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Overheat|Runtime")
		EFortWeaponOverheatState OverheatState;

	/* HUD Stuff */
	// Determines whether or not the ammo counter is shown on the player's HUD 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD")
		bool bShouldDisplayAmmoCounter = true;

	// Determines whether or not the ammo counter is shown on the player's HUD while Secondary Fire is active
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD")
		bool bShouldDisplayAmmoCounterDuringSecondaryFire = true;

	// Determines whether or not the ammo reserve should be displayed on the player's HUD
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD")
		bool bShouldHideReserveAmmo = false;

	/* Camera Stuff */
	// If true, the player's aim location stays the same when player aims down sights.
	// If false, it may move to a slightly different position
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool bMaintainAimLocationDuringTargeting;

	// When true, uses the scope targeting. Not needed if the weapon has no scope.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool bUseScopeTargeting;

	// Offsets the position of the Muzzle's effects while scope targeting by the specified amount in any direction.
	UPROPERTY(EditDefaultsOnly, Category = "Camera|Scope")
		FVector	ScopeTargetingMuzzleOffset;

	// Uses the 1P Camera when targeting
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool bUseFirstPersonTargeting;

	// Reduces controller aim assist while targeting
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool bUseReducedTargetingAimAssist;

	// When set to true, this weapon will create decals on impact
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals")
		bool bUseImpactDecals;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals", meta = (DisplayName = "Minimum Decal Size"))
		FVector	DecalSizeMin;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals", meta = (DisplayName = "Maximum Decal Size"))
		FVector	DecalSizeMax;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals", meta = (DisplayName = "Minimum Decal Lifespan"))
		float DecalLifespanMin;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals", meta = (DisplayName = "Maximum Decal Lifespan"))
		float DecalLifespanMax;

	// Sets the decal colour at the start of its lifetime
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals")
		FLinearColor DecalColorStart;

	// Sets the decal colour at the end of its lifetime
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals")
		FLinearColor DecalColorEnd;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals")
		TSoftObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals")
		TSoftObjectPtr<UTexture2D> DecalTexture;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals")
		TArray<TEnumAsByte<EPhysicalSurface>> SurfaceAcceptingDecals;

	// Distance quality for each effect quality setting
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Decals|Quality")
		FFortEffectDistanceQuality DecalSignificance;

	/* Character and Weapon Animations */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Animation")
		UAnimMontage* FireAnimation; // 0xff0(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Animation")
		UAnimMontage* FireDownsightsAnimation; // 0xff8(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Animation")
		UAnimMontage* FireFromCrouchWalkAnimation; // 0x1000(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Animation")
		UAnimMontage* CockingAnimation; // 0x1008(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Animation")
		UAnimMontage* OverheatedAnimation; // 0x1028(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponFireMontage; // 0x1010(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponFireDownsightsMontage; // 0x1018(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponFireFromCrouchWalkMontage; // 0x1020(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponCockingMontage; // 0x1028(0x08)

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponOverheatedAnimation; // 0x1028(0x08)

protected:
	//allows you to do something when weapon fully overheats
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void OnStartOverheated();
};