#pragma once
#include "CoreMinimal.h"
#include "FortWeapon.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "BuildingActor.h"
#include "FortniteGame.h"
#include "FortDamageSourceInterface.h"
#include "Markers/FortMarkableActorInterface.h"
#include "FortAbilitySetDeliveryInfo.h"
#include "FortProjectileMovementInterface.h"
#include "FortTargetSelectionInterface.h"
#include "BuildingGameplayActor.generated.h"

class AActor;
class AFortPlayerController;
class UFortAbilitySet;
class UFortDamageSet;
class UFortGameplayAbility;
class UPrimitiveComponent;
class ABuildingGameplayActor;
class UProjectileMovementComponent;

USTRUCT(BlueprintType)
struct FMarkedActorDisplayInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText DisplayName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSoftObjectPtr<UTexture2D> Icon;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<UUserWidget> CustomIndicatorClass;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor PrimaryColor;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	USoundBase* Sound;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortMarkedActorScreenClamping ScreenClamping;
};

USTRUCT(BlueprintType)
struct FProximityBasedGEDeliveryInfoBase {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortDeliveryInfoRequirementsFilter DeliveryRequirements;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortProximityBasedGEApplicationType ProximityApplicationType;
};

USTRUCT(BlueprintType)
struct FProximityBasedGEDeliveryInfoHard : public FProximityBasedGEDeliveryInfoBase {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FGameplayEffectApplicationInfoHard> EffectsToApply;
};
USTRUCT(BlueprintType)
struct FBuildingGameplayActorAbilityDeliveryBucket {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTag Tag;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FProximityBasedGEDeliveryInfoHard> ProximityEffectBuckets;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAbilitySetDeliveryInfo> PawnPersistentAbilitySetBuckets;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<FFortAbilitySetHandle> PersistentlyAppliedAbilitySets;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	uint8 bEnabled: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bEnabledByDefault: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bHasGEsToApplyOnTouch: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bHasGEsToApplyOnPulseTimer: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bHasPersistentEffects: 1;
};

USTRUCT(BlueprintType)
struct FBuildingGameplayActorAbilityDeliveryInfo {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FBuildingGameplayActorAbilityDeliveryBucket> DeliveryBuckets;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float ProximityPulseInterval;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bHasGEsToApplyOnTouch: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bHasGEsToApplyOnPulseTimer: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bHasPersistentEffects: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	ABuildingGameplayActor* OwningActor;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<AActor*> DeferredTouchActorsToProcess;
};

UCLASS(Blueprintable, MinimalAPI)
class ABuildingGameplayActor : public ABuildingActor, public IFortTargetSelectionInterface, public IFortDamageSourceInterface, public IFortMarkableActorInterface, public IFortProjectileMovementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFortAbilitySet* AbilitySet;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UFortAbilitySet* InherentAbilitySets[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFortDamageSet* DamageSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle DamageStatHandle;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreInstigatorCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddOwnerVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AbilitySourceLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildingGameplayActorAbilityDeliveryInfo DeliverableAbilityInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyDefaultEnabledAbilityBucketsOnInit: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseSimpleActorTouchSetupForAbilityBuckets: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMarkedActorDisplayInfo MarkerDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* RegisteredTouchComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponent* ProjectileMovementComponent;
    
public:
    ABuildingGameplayActor();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTouchComponentForAbilityDeliveryInfo(UPrimitiveComponent* PrimitiveComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetInitialVelocity(const FVector& InitialVelocity);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreInstigatorCollision(bool bShouldIgnore);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetAbilitySourceLevel(int32 NewAbilitySourceLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReplicatedVelocityStartOrStop(bool bStart);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRegisteredTouchComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnRegisteredTouchComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDropped(bool bValidLocation, bool bPassesPlacementRestrictions, bool bWasIntentionallyPlaced);
    
    UFUNCTION(BlueprintCallable)
    void K2_RemoveGameplayCue(FGameplayTag GameplayCueTag);
    
    UFUNCTION(BlueprintCallable)
    void K2_ExecuteGameplayCueWithParams(FGameplayTag GameplayCueTag, const FGameplayCueParameters& GameplayCueParameters);
    
    UFUNCTION(BlueprintCallable)
    void K2_ExecuteGameplayCue(FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context);
    
    UFUNCTION(BlueprintCallable)
    void K2_AddGameplayCue(FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FTransform GetTargetingSourceTransform(EFortAbilityTargetingSource Source) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ForceChangeOwnerInstigator(AFortPlayerController* NewInstigator);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void EnableAbilityDeliveryInfo(FGameplayTag BucketTag);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DisableAbilityDeliveryInfo(FGameplayTag BucketTag);
	
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    FTransform GetTargetingTransform(EFortAbilityTargetingSource Source, UFortGameplayAbility* SourceAbility) const override PURE_VIRTUAL(GetTargetingTransform, return FTransform{};);
    
};


