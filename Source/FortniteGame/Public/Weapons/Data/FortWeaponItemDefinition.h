// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Cosmetics/Items/AthenaItemWrapDefinition.h"
#include "STW/Items/FortAlterationItemDefinition.h"
#include "FortniteGame.h"
#include "Customization/CustomCharacterPart.h"
#include "Items/FortWorldItemDefinition.h"
#include "Engine/SkeletalMesh.h"
#include "FortWeaponItemDefinition.generated.h"

USTRUCT()
struct FFortCreativeTagsHelper
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		TArray<FName> CreativeTags;
};

UCLASS()
class FORTNITEGAME_API UFortWeaponItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

	/* Basic Weapon Item Info */
public:
	UFortWeaponItemDefinition();
	// Actor this weapon uses
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Base", meta = (AssetBundles = "Equipped,ClientAthena,ServerAthena"))
		TSoftClassPtr<UObject> WeaponActorClass;

	// Stats used by this weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Base")
		FDataTableRowHandle WeaponStatHandle;

	// Determines what type of firing mode a weapon uses when the 
	// Primary Ability is activated, On-Press, Automatic, OnRelease, OnPressAndRelease
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Base")
		TEnumAsByte<EFortWeaponTriggerType> TriggerType;

	// Determines what type of firing mode a weapon uses when the Secondary Ability is activated, 
	// On-Press, Automatic, OnRelease, OnPressAndRelease, not in 9.10
	UPROPERTY(VisibleAnywhere, Category = "Weapon Item Info|Base")
		TEnumAsByte<EFortWeaponTriggerType> SecondaryTriggerType;

	//Displays which STW Ore or Crystal this weapon is, Invalid displays no Ore/Crystal and only the weapon name
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Item Info|Base")
		EFortDisplayTier DisplayTier;

	/* Weapon Overrides */
	//Overrides which mesh is used by this weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Overrides", meta = (AssetBundles = "Equipped,DroppedItem,ClientAthena,ServerAthena"))
		TSoftObjectPtr<USkeletalMesh> WeaponMeshOverride;

	//Overrides which wrap is being used by this weapon, not in 9.10 (Used in Chapter 2 Season 6 on the one funny Legendary Assault Rifle)
	UPROPERTY(VisibleAnywhere, Category = "Weapon Item Info|Overrides")
		TSoftObjectPtr<UAthenaItemWrapDefinition> IntrinsicOverrideWrap;


	/* Weapon Ammo Info */
	// Ammo type used by this weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Ammo")
		TSoftObjectPtr<UFortWorldItemDefinition> AmmoData;

	// Rate that ammo recharges at, not in 9.10 (used by TNTinas Ka-Boom Bow in Chapter 2 Season 2)
	UPROPERTY(VisibleAnywhere, Category = "Weapon Item Info|Ammo")
		FScalableFloat WeaponRechargeAmmoRate;

	// Percentage of Ammo used for the weapon to be considered on Low Ammo? (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Ammo")
		float LowAmmoPercentage;

	// Not sure what this is used for, but is used on items such as the Grappler, and some throwable items iirc
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Ammo")
		bool bUsesCustomAmmoType = false;

	// Not quite sure what this is used for, but is used on items such as the Grappler
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Ammo")
		bool bUsesPhantomReserveAmmo = false;


	/* Weapon Alterations */
	//Base Alteration, without any perks or anything
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Alterations")
		TSoftObjectPtr<UFortAlterationItemDefinition> BaseAlteration;

	//Base Cosmetic Alteration, without any perks or anything
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Alterations")
		TSoftObjectPtr<UFortAlterationItemDefinition> BaseCosmeticAlteration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Alterations")
		FName AlterationSlotsLoadoutRow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Alterations")
		FName BaselineAlterationSlotsLoadoutRow;


	/* Cosmetic */
	//Array of character parts to be equipped when item is held
		TArray<UCustomCharacterPart*> EquippedCharacterParts;

	/* Weapon Abilities */
	// Ability that gets activated on Primary Fire action pressed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Abilities")
		TSoftClassPtr<UGameplayAbility> PrimaryFireAbility;

	// Ability that gets activated on Secondary Fire action pressed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Abilities")
		TSoftClassPtr<UGameplayAbility> SecondaryFireAbility;

	// Ability that gets activated on Reload action pressed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Abilities")
		TSoftClassPtr<UGameplayAbility> ReloadAbility;

	// Ability that gets activated on hit
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Item Info|Abilities")
		TSoftClassPtr<UGameplayAbility> OnHitAbility;

	// Abilities that are active while the weapon is equipped
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Abilities")
		TArray<TSoftClassPtr<UGameplayAbility>> EquippedAbilities;


	/* Weapon Reloading Info */
	// Allows player to Aim Down Sights while a weapon is reloading
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reloading")
		bool bAllowTargetingDuringReload = false;

	// Doesn't allow player to start reloading until they aren't targeting
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reloading")
		bool bTargetingPreventsReload = false;


	/* Weapon Reticle */
	// Duration of Hitmarker display on screen
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle|Hit Notify")
		float HitNotifyDuration;

	// Hitmarker image(?)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle|Hit Notify")
		TSoftObjectPtr<UTexture2D> HitNotifyImage;

	// Hitmarker location image(?)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle|Hit Notify")
		TSoftObjectPtr<UTexture2D> HitNotifyLocationImage;

	// Corner angles for Hitmarkers (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle|Hit Notify")
		TArray<float> HitNotifyCornerAngles;

	// Controls Hitmarker opacity (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle|Hit Notify")
		TSoftObjectPtr<UCurveFloat> HitNotifyOpacityCurve;

	// Determines whether or not the reticle displays each line from the center of the image, or the inside of the image
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		bool bReticleCornerOutsideSpreadRadius = false;

	// Standard reticle image, probably shouldn't use this in most cases
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleImage;

	// Image displayed on reticle for mobile users with autofire enabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleAutoFireImage;

	// Rotation of the reticle lines, also can be used to display less than 4 lines
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TArray<float> ReticleCornerAngles;

	// Reticle image shown in the center of the reticle, use this over using ReticleImage in most cases
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleCenterImage;

	// Alternative image for reticle center, not sure what this does
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleAltCenterImage;

	// Outer reticle image, not sure what this does
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleOuterImage;

	// Alternative image for outer reticle, not sure what this does
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleAltOuterImage;

	// Reticle image shown when weapon is using First Shot Accuracy
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleCenterPerfectAimImage;

	// Modifies positioning of the Reticle Center Image, usually used by stuff like the Grenade Launcher and it's many variants
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		FVector2D ReticleCenterImageOffset;

	// Reticle image that is shown when targeting something invalid, used by the Grappler when it's out of range
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		TSoftObjectPtr<UTexture2D> ReticleInvalidTargetImage;

	// Reticle image shown when the weapon's muzzle is being obstructed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Reticle")
		UTexture2D* MuzzleBlockedImage;


	/* Weapon Tags */
	// Tags used for analytics (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Tags|Analytics")
		FGameplayTagContainer AnalyticTags;

	// FNames used for analytics (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Tags|Analytics")
		TArray<FName> ActualAnalyticFNames;

	// Gameplay Tags that are granted to player by the weapon (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Tags|Gameplay")
		FGameplayTagContainer PlayerGrantedGameplayTags;


	/* Miscellaneous Weapon Info */
	// Percentage of durability needed for a weapon to be considered degraded? (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "World Item Info|Durability")
		float DegradedPercentage;

	// When secondary fire is pressed, it interrupts the primary fire, not in 9.10
	UPROPERTY(VisibleAnywhere, Category = "Weapon Item Info|Misc")
		bool bAllowSecondaryFireToInterruptPrimary;

	// Makes a weapon have to always charge up to it's minimum charge specified in the StatRowHandle (this is an assumption)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Misc")
		bool bAlwaysChargeUpToMin = false;

	//Makes weapon valid for being the last equipped item? I genuinely have no clue what this does
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Misc")
		bool bValidForLastEquipped = true;

	//Prevents weapon from being preloaded? I genuinely have no clue what this does
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Item Info|Misc")
		bool bPreventDefaultPreload = true;

	/* Creative Info */
	// Adds tags to a weapon for sorting purposes in the creative inventory, not in 9.10
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Item Info|Creative")
		FFortCreativeTagsHelper CreativeTagsHelper;

	
	//protected:
	//UPROPERTY()
	//	AFortWeaponAsyncLoadHelper* AsyncLoadHelper;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Weapon", GetFName());
	}
};