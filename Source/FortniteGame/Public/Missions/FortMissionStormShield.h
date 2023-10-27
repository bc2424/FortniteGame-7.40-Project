#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Styling/SlateBrush.h"
#include "Templates/SubclassOf.h"
#include "FortniteGame.h"
#include "FortMissionStormShield.generated.h"

class AFortMissionStormSafeZone;
class UEnvQuery;
class UFortStormShieldComponent;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneComponent;
class UStaticMeshComponent;
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormShieldReachedTargetLocation, FVector, Location);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormShieldReachedTargetRadius, float, Radius);

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FStormShieldMoveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartingLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeAreaStartLocationChangeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeAreaFinishLocationChangeTime;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FStormShieldRadiusGrowthData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartingRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrowthRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeAreaStartRadiusChangeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeAreaFinishRadiusChangeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMissionStormShieldState State;
};

UCLASS(Abstract, Blueprintable)
class FORTNITEGAME_API AFortMissionStormShield : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ShieldRing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> SafeFromStormPlayerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> InStormPlayerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> SafeFromStormEnemyEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> InStormEnemyEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapWorldScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ReplicatedRadius, meta=(AllowPrivateAccess=true))
    float ReplicatedRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RadiusGrowthData, meta=(AllowPrivateAccess=true))
    FStormShieldRadiusGrowthData RadiusGrowthData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FStormShieldMoveData MoveData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool UseGrowthRateDirectly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bAntiStormShield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadiusToWorldScaleConversion;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnStormShieldReachedTargetRadius OnStormShieldReachedRadius;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnStormShieldReachedTargetLocation OnStormShieldReachedLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFortMissionStormSafeZone> SafeAreaTemplate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnvQuery* StormShieldQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentLocalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* StormMiniMapMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* StormMiniMapMaterialMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush StormMiniMapMaterialBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* StormMainMapMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* StormMainMapMaterialMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush StormMainMapMaterialBrush;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<AFortMissionStormSafeZone*> SafeAreas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFortStormShieldComponent*> StormShieldComponents;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterWithGameState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoHideRadius;
    
public:
    AFortMissionStormShield();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateRadiusVisuals();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    AFortMissionStormSafeZone* SpawnSafeAreaAtLocation(const FVector& InLocation, const float InRadius);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTargetRadiusSizeChangeOverGrowthRate(const float InTargetRadius, const float InGrowthRate, bool bUseGrowthRateDirectly);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTargetLocationToMoveTo(const FVector InTargetLocation, const float InMoveRate);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRadiusOfShield(const float InRadius);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool RemoveAndDestroySafeArea(AFortMissionStormSafeZone* AreaToRemove);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ReplicatedRadius();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_RadiusGrowthData();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void InitializeRadiusValue(const float InRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSafeZones(TArray<AFortMissionStormSafeZone*>& OutSafeZones);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DestroyStormShield();
};

