// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponItemDefinition.h"
#include "Particles/ParticleSystem.h"
#include "FortProjectileBase.h"
#include "GameplayTagContainer.h"
#include "GameplayTags.h"
#include "FortWeaponRangedItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortWeaponRangedItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()

public:
	/* Basic Ranged Weapon Item Info */
	//Makes a weapon use First Shot Accuracy when set to true
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Base")
		bool bShouldUsePerfectAimWhenTargetingMinSpread = true;

	//Allows players to Aim Down Sights while in the air
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Base")
		bool bAllowADSInAir = false;

	//If set to true, makes Secondary Fire ability consume ammo from weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Base")
		bool bSecondaryFireRequiresAmmo = false;


	/* Ranged Weapon Projectiles */
	//Choose what projectile you want a ranged weapon to shoot, if you wish to use hitscan then leave empty
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Projectile")
		TSoftClassPtr<AFortProjectileBase> ProjectileTemplate;

	//Forces projectile tooltip, whatever that means
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Projectile")
		bool bForceProjectileTooltip = false;


	/* Ranged Weapon Shell FX */
	//Specify which Shell FX a weapon should use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Shell FX")
		TSoftObjectPtr<UParticleSystem> BulletShellFXTemplate;

	//Allows weapon to spawn Shell FX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Shell FX")
		bool bShouldSpawnBulletShellFX;


	/* Ranged Weapon Trace Info */
	//If set to true, weapon uses Native Weapon Trace
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Weapon Trace")
		bool bUseNativeWeaponTrace = false;

	//If set to true, allows weapon to shoot through any object in the world
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Weapon Trace")
		bool bTraceThroughWorld = false;

	//If set to true, allows weapon to shoot through pawns, such as players
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Weapon Trace")
		bool bTraceThroughPawns = false;


	/* Miscellaneous Ranged Weapon Info */
	//Enables some anim that adds a delay to double pump
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Misc")
		bool bDoNotAllowDoublePump = false;

	//I have no idea what this would do
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Misc")
		bool bUseOnTouch = false;

	//If set to true, shows where your bullet went due to bloom on the hitmarker, used by shotguns in Athena
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Item Info|Reticle|Hit Notify")
		bool bShowReticleHitNotifyAtImpactLocation = false;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Weapon", GetFName());
	}
};