// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FortniteGame.h"
#include "FortGameplayCueAOEInfo.h"
#include "AttributeSet.h"
#include "FortGameplayAbility_Structs.generated.h"

class UFortWeaponItemDefinition;
class UFortItemDefinition;
USTRUCT(BlueprintType)
struct FGameplayTagMessage
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer Tags;                                             
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Text;                                    
};

USTRUCT(BlueprintType)
struct FFortRechargingActionTimer
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMulticastDelegateProperty* OnActivate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMulticastDelegateProperty* OnDeactivate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMulticastDelegateProperty* OnActivationFailed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ChargeRate;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActiveExpenseRate;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PassiveExpenseRate;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinActivationDurationTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinActivationCharge;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActiveCooldownTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Charge;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsActive;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsCharging;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsPassive;
};
USTRUCT(BlueprintType)
struct FFortAbilityCost
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EFortAbilityCostSource CostSource;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FScalableFloat CostValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UFortItemDefinition* ItemDefinition;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bOnlyApplyCostOnHit;
};

USTRUCT(BlueprintType)
struct FAbilityTrackedActorSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FScalableFloat MaximumTrackedActors;
};

USTRUCT(BlueprintType)
struct FFortCharacterPartMontageInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<EFortCustomPartType> CharacterPart;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* AnimMontage;
};

USTRUCT(BlueprintType)
struct FFortGameplayAbilityBehaviorDistanceData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer DistanceDataTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Distance;
};


USTRUCT(BlueprintType)
struct FFortTargetFilter
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<EFortTargetSelectionFilter> ActorTypeFilter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClass* ActorClassFilter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeInstigator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUseTrapsOwningPawnAsInstigator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeRequester;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeAllAttachedToInstigator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeAthenaVehicleOfInstigator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeAllAttachedToRequester;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludePawnFriends;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeFriendlyAI;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludePawnEnemies;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeNonPawnFriends;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeNonPawnEnemies;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bConsiderFriendlyFireWhenExcludingFriends;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeDBNOPawns;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeWaterVolumes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeAthenaVehicle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeAthenaVehicleFromObstructionChecks;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeWithoutNavigationCorridor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeNonPlayerBuiltPieces;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludePlayerBuiltPieces;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeNonBGABuildings;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeNonBlockingHits;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeProjectiles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bTraceComplexCollision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer ExclusionGameplayTags;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bPropagateToVehiclePassengers;

};


USTRUCT(BlueprintType)
struct FFortAbilityTargetSelection
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<EFortTargetSelectionShape> Shape;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CustomShapeComponentName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EFortTargetSelectionTestType TestType;      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EFortAbilityTargetingSource PrimarySource;  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EFortAbilityTargetingSource SecondarySource;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FScalableFloat Range;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector HalfExtents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FScalableFloat ConeYawAngle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FScalableFloat ConePitchAngle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FScalableFloat ConeMinRadius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FFortTargetFilter TargetFilter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExcludeObstructedByWorld;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bShouldAttachedActorsObstructTarget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCreateHitResultWhenNoTargetsFound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUseProjectileRotationForDamageZones;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EFortAbilityTargetSelectionUsage TargetSelectionUsage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxTargets;
};


USTRUCT(BlueprintType)
struct FFortAbilityTargetSelectionList
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FFortAbilityTargetSelection> List;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bStopAtFirstSuccess;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bKeepCheckingListOnIndestructibleHit;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUseWeaponRanges;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUseMaxYawAngleToTarget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxYawAngleToTarget;
};


USTRUCT(BlueprintType)
struct FFortGameplayEffectContainer
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTag ApplicationTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FFortAbilityTargetSelectionList TargetSelection;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UClass*>TargetGameplayEffectClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UClass*>OwnerGameplayEffectClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer ActivationCues;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer ImpactCues;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUseCalculationInTooltips;
};

USTRUCT(BlueprintType)
struct FFortGameplayEffectContainerSpec
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FFortAbilityTargetSelectionList TargetSelection;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FGameplayEffectSpecHandle> TargetGameplayEffectSpecs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FGameplayEffectSpecHandle> OwnerGameplayEffectSpecs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer ActivationCues;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer ImpactCues;

};

USTRUCT(BlueprintType)
struct FGameplayEffectApplicationInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere)
	float Level;

};

USTRUCT(BlueprintType)
struct FGameplayEffectApplicationInfoHard
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> GameplayEffect;
	
	UPROPERTY(EditAnywhere)
	float Level;

};

USTRUCT(BlueprintType)
struct FFortGameplayAbilityMontageInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UAnimMontage* MontageToPlay;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float AnimPlayRate;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float AnimRootMotionTranslationScale;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortGameplayAbilityMontageSectionToPlay MontageSectionToPlay;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName OverrideSection;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bPlayRandomSection;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortCharacterPartMontageInfo> CharacterPartMontages;
};

class FORTNITEGAME_API FortGameplayAbility_Structs
{
public:
	FortGameplayAbility_Structs();
	~FortGameplayAbility_Structs();
};
