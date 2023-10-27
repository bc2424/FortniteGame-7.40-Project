// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Components/AudioComponent.h"
#include "FortniteGame.h"
#include "FortGameplayAbility_Structs.h"
#include "FortWeaponAnimSet.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ForceFeedbackEffect.h"
#include "GameplayAbilitySpec.h"
#include "Math/Color.h"
#include "GameplayEffectTypes.h"
#include "Sound/SoundBase.h"
//#include "SkeletalMeshComponentBudgeted.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
//#include "SignificanceManager.h"
#include "FortWeapon.generated.h"

class USkeletalMeshComponentBudgeted;

USTRUCT(BlueprintType)
struct FFortEffectDistanceQuality
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MinDistanceCinematic;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MinDistanceEpic;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MinDistanceHigh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MinDistanceMedium;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MinDistanceLow;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAllowCinematic;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAllowEpic;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAllowHigh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAllowMedium;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAllowLow;

};
USTRUCT(BlueprintType)
struct FFortAbilitySetHandle
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TWeakObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FGameplayAbilitySpecHandle> GrantedAbilityHandles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FActiveGameplayEffectHandle> AppliedEffectHandles;

};

USTRUCT(BlueprintType)
struct FWeaponHudData
{

	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName KeyActionName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName GamepadActionName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText ActionDescription;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API AFortWeapon : public AActor
{
	GENERATED_BODY()

		/* ---------------- */
		/* Uncategorized */
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int EquippedWeaponDestroyWrapperRepCounter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int CurrentGunFireIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int CurrentShotLogIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int32> ShotLogFlags;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int ChargeStatusPack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bIgnoreTryToFireSlotCooldownRestriction;

	/* ---------------- */
	/* Camera */
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		UClass*	CameraBase3PClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		UClass*	CameraTargeting3PClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		UClass* CameraBase1PClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		UClass* CameraTargeting1PClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		UClass* ImpactCameraShake;

	/* ---------------- */
	/* Reticle */
protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		bool bShouldDrawNativeReticle;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		UTexture2D*	ReticleImage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		FColor ReticleDefaultColor = FColor(255,255,255,255);

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		FColor ReticleEnemyColor = FColor(255,0,0,255);

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		FColor ReticleBuildingColor = FColor(255,255,255,255);

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		UTexture2D* HitNotifyReticleImage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		float HitNotifyDisplayDuration;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		UTexture2D* ReticleCenterImage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		UTexture2D* ReticleCenterPerfectAimImage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		UTexture2D* MuzzleBlockedReticleImage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		float ReticleDefaultPrimaryStrikeAngle;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		float ReticleDefaultSecondaryStrikeAngle;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		bool bSupportsAutofireAtReticleTarget = true;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		FColor CurrentReticleColor;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		FVector CurrentDamageStartLocation;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		FVector CurrentAdjustedAimDirection;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Reticle")
		TArray<FWeightedBlendable> ScopePostProcessMaterial;

	/* ---------------- */
	/* Offset */
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Offset")
		FVector	TargetSourceOffset;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Offset")
		FVector	TargetSourceOffsetWhileCrouched;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Offset")
		FVector	TargetSourceOffsetWhileTargeting;

	/* ---------------- */
	/* Customization */
public:

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Customization")
		TArray<UFortAlterationItemDefinition*> AppliedAlterations;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Customization")
		UAthenaItemWrapDefinition* AppliedItemWrap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customization")
		TArray<UMaterialInterface*>	DefaultWeaponMaterials;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customization")
		FName CosmeticStatToObserve;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customization")
		int CosmeticStatValue;

	/* ---------------- */
	/* Misc */
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Data")
		bool bIsEquippingWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Data")
		bool bIsReloadingWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Data")
		bool bIsChargingWeapon;

	UPROPERTY(Transient, VisibleAnywhere, Category = "Weapon Data")
		float TimerIntervalAdjustment;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon Data")
		float InputQueueTimePercent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Weapon Data")
		bool bAllowTargeting;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon Data")
		bool bIsTargeting;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon Data")
		float LastTargetingTransitionTime;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Weapon Data")
		bool bTraceThroughPawns;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Weapon Data")
		bool bTraceThroughWorld;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Weapon Data")
		int TraceThroughPawnsLimit;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Weapon Data")
		int TraceThroughBuildingsLimit;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Weapon Data")
		bool bUseProjectileTrace;

	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, Category = "Weapon Data")
		int BurstFireCounter;

	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, Category = "Weapon Data")
		float ChargeTime;

	UPROPERTY(Transient, VisibleAnywhere, Category = "Weapon Data")
		bool bInitializedWeaponItem;

	UPROPERTY(Transient, VisibleAnywhere, Category = "Weapon Data")
		bool bUpdateLocalAmmoCount;

	UPROPERTY(config, VisibleAnywhere, Category = "Weapon Data|Network")
		float MaxWeaponSwitchNetworkWaitTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD")
		TArray<FWeaponHudData> HudKeyActionData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Data")
		UClass* AttachedTrajectoryIndicator;

	/* ---------------- */
	/* Ability */
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		TArray<FFortGameplayAbilityBehaviorDistanceData> GameplayAbilityBehaviorDistanceData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		UGameplayAbility* ActiveAbility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		FGameplayAbilitySpecHandle PrimaryAbilitySpecHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		FGameplayAbilitySpecHandle SecondaryAbilitySpecHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		FGameplayAbilitySpecHandle ReloadAbilitySpecHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		TArray<FGameplayAbilitySpecHandle> EquippedAbilityHandles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		TArray<FFortAbilitySetHandle> EquippedAbilitySetHandles;

	// When true, abilities get removed from the player when this weapon is removed from their inventory.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
		bool bRemoveAbilitiesWhenRemovedFromInventory;

	/* ---------------- */
	/* Effects */
public:

	UPROPERTY(BlueprintReadOnly, Transient, Category = "Effects")
		float PersistentFXStartTime;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		float MinimumTimeForPersistentFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		bool bImpactFXAttachedToHitActor;

	UPROPERTY(EditAnywhere, Category = "Effects")
		UParticleSystem* ImpactPhysicalSurfaceEffects[26];

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Force Feedback")
		UForceFeedbackEffect* PrimaryForceFeedbackEffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Force Feedback")
		UForceFeedbackEffect* SecondaryForceFeedbackEffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Force Feedback")
		UForceFeedbackEffect* PrimaryImpactForceFeedbackEffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects|Force Feedback")
		UForceFeedbackEffect* SecondaryImpactForceFeedbackEffect;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		AActor* CachedFXManager;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects Quality")
		FFortEffectDistanceQuality FireFXSignificance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		FName MuzzleSocketName = "Muzzle";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		FName MuzzleFalloffSocketName = "MuzzleFalloff";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		FName WeaponHandSocketNameOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effects")
		FName LeftHandWeaponHandSocketNameOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bIsPlayingFireFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bFireFXTriggered;


	/* ---------------- */
	/* Runtime */
public:
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		float LastFireAbilityTime;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		float LastFireTime;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		AActor* LockOnTargetCandidate;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		bool bPendingDestroyDueToDurabilityOrStackCount;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		bool bCompletedAppliedAlterationsLoad;
	
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		bool bReplicatedAppliedAlterationsWithNoInstigator;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		bool bCompletedWeaponLoad;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		float LastReloadTime;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		float LastSuccessfulReloadTime;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		float CurrentReloadDuration;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Weapon Data|Runtime")
		FGuid ItemEntryGuid;

	UPROPERTY(Transient, BlueprintReadWrite, EditAnywhere, Category = "Weapon Data|Runtime")
		int WeaponLevel;

	UPROPERTY(Transient, BlueprintReadWrite, EditAnywhere, Category = "Weapon Data|Runtime")
		int AmmoCount;

	UPROPERTY(Transient, BlueprintReadWrite, EditAnywhere, Category = "Weapon Data")
		UFortWeaponItemDefinition* WeaponData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Data")
		UFortWeaponItemDefinition* CosmeticOverrideWeaponData;

	/* ---------------- */
	/* Animation */
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UAnimMontage* PrimaryAbilityAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UAnimMontage* EquipAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UAnimMontage* ReloadAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		TArray<UAnimMontage*> CustomReloadAnimationPerAmmoToFill;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UAnimSequence* PoseOffsetAnimSequence;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UAnimSequence* PoseOffsetAnimSequenceFemaleOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UAnimMontage* UnableToPerformActionMontageOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Animation")
		UFortWeaponAnimSet* WeaponPawnAnimSet;

	// not in season 9
	UPROPERTY(VisibleAnywhere, Category = "Character Animation")
		UAnimInstance* WeaponPawnAnimLayerOverlayClass;

	// not in season 9
	UPROPERTY(VisibleAnywhere, Category = "Character Animation")
		UFortWeaponAnimSet* WeaponPawnAnimsetOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponPrimaryAbilityMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponEquipMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Animation")
		UAnimMontage* WeaponReloadMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Animation")
		TArray<UAnimMontage*> CustomWeaponReloadMontagePerAmmoToFill;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Animation")
		UAnimSequence* WeaponChargeAnimSequence;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Animation")
		TEnumAsByte<EFortWeaponCoreAnimation> WeaponCoreAnimation;


	/* ---------------- */
	/* Weapon Sounds */
protected:
	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* ImpactPhysicalSurfaceSounds[26];

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Sound")
		USoundBase*	DestroyedSound;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Sound")
		USoundBase* OutOfAmmoSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase*	ReloadSounds[3];

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sound")
		UPrimaryDataAsset* HitNotifyAudioBank;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sound")
		bool bUsingSecondaryFireAudio;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sound")
		int FireAudioChannelWantsToPlay;

	UPROPERTY(EditAnywhere, Category = "Sound")
		UAudioComponent* FireAudioChannels[4];

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase*	PrimaryFireSound1P;

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase*	PrimaryFireSound[3];

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* PrimaryFireStopSound1P;

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* PrimaryFireStopSound[3];

	UPROPERTY(EditAnywhere, Category = "Sound")
		float PrimaryFireSoundFadeOutTime = 0.25f;

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase*	SecondaryFireSound[3];

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase*	SecondaryFireStopSound[3];

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* ChargeFireSound[3];

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* TargetingStartSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* TargetingEndSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sound")
		USoundBase* Sound_ScopeZoomIn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Sound")
		USoundBase* Sound_ScopeZoomOut;

	// Sets default values for this actor's properties
	AFortWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	 USkeletalMeshComponentBudgeted* WeaponMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//USkeletalMeshComponent* LeftHandWeaponMesh;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	// uses the weapon's durability with a set scale
	UFUNCTION(BlueprintCallable, Category = "Runtime")
		void UseWeaponDurability(float DurabilityScale);

	// K2 notification when weapon is hidden/shown
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Runtime")
		void OnWeaponVisibilityChanged(bool bVisible);

	// Blueprint event fired when the weapon is attached to the owning pawn
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Runtime", meta = (DisplayName = "OnEquippedAndAttached"))
		void OnWeaponAttached();

	// stops fire effects that are being played by this weapon
	UFUNCTION(BlueprintCallable, Category = "Effects", meta = (DisplayName = "StopWeaponFireEffects"))
		void StopWeaponFireFX();

	// Event called when weapon starts charging up from 0%
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Charging")
		void OnStartCharge();

	// Event called when weapon charge drops to 0%
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Charging")
		void OnEndCharge();

	// Called when weapon charge starts to decrease
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Charging")
		void OnChargeDown();

	// Called when weapon charge starts to increase (not necessarily from 0%)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Charging")
		void OnChargeUp();

	// Blueprint notification that the weapon's ammo count has changed
	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category = "Runtime")
		void OnAmmoCountChanged();

	// Event called for effects associated with reaching the minimum charge of the weapon.
	// NOTE: This event is ONLY called on the local client (i.e. the client carrying the weapon).
	// For all other clients, you need to also use "On Remote Client Reached Min Charge."
	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category = "Charging", meta = (DisplayName = "On Local Client Reached Minimum Charge"))
		void OnReachedMinCharge();

	// Event called for effects associated with reaching the maximum charge of the weapon.
	// NOTE: This event is ONLY called on the local client (i.e. the client carrying the weapon).
	// For all other clients, you need to also use "On Remote Client Reached Max Charge."
	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category = "Charging", meta = (DisplayName = "On Local Client Reached Maximum Charge"))
		void OnReachedMaxCharge();

	// Blueprint event called when weapon fire FX is played.
	// If bPersistentFire is true, the weapon effects will fire in a loop.
	// NOTE: This function is NOT guaranteed to happen on all clients (and in fact will NOT play if the client is of lower significance / culled), 
	// so it is NOT safe to use this function to play sounds.  Built in sound functions should be used instead.
	// You should also beware changing state on the blueprint actor since you can't be guaranteed the state-change would occur.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Effects", meta = (DisplayName = "OnPlayWeaponFireEffects"))
		void OnPlayWeaponFireFX(bool bPersistentFire, bool bSecondaryFire);

	// Blueprint event called when the owning player starts/stops targeting downsights
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Runtime")
		void OnSetTargeting(bool bNewIsTargeting);

	// Blueprint notification that this weapon has been unequipped. 
	// This is not called on weapons belonging to ROLE_SimulatedProxy pawns. 
	// See Attached & Detached events for a similar event that happens on all network clients
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Runtime", meta = (DisplayName = "OnLocalUnEquip"))
		void K2_OnUnEquip();

	// Consumes a specified amount of ammo when called
	UFUNCTION(BlueprintCallable, Category = "Runtime", meta = (DisplayName = "ConsumeAmmo"))
		void K2_ConsumeAmmo(int32 Quantity);

	// Gets the GUID of an instance of this weapon from the player's inventory
	UFUNCTION(BlueprintCallable, Category = "Runtime")
		FGuid GetInventoryGUID();
	// inventory item guid
	FGuid WeaponGUID;

	// When called, gets the weapon's current charge percentage
	UFUNCTION(BlueprintCallable, Category = "Charging")
		float GetChargePercent();
	// return value for charge percent
		float ChargePercent;

	UFUNCTION(BlueprintCallable)
		FVector GetMuzzleLocation() { FVector ReturnValue; return ReturnValue; };
};

/* Recreated by sizzy#5265*/ /*Normally I would remove things like this but I am leaving it solely out of goddamn respect*/