#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "BulletWhipTrackerComponentBase.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FBulletWhipTrackerData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bAttachSoundToOwner;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float PassByRadiusMax;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float PassByRadiusMin;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	USoundBase* PassByFarSound;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	USoundBase* PassByCloseSound;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MinimumTriggerDistance;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float TriggerAheadDistance;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
	UAudioComponent* CurrentAudioComp;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	float PreviousPlaneDotProd;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	float CachedPassDistance;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	float PassByClosenessIntensity;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	bool bActive;
};

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UBulletWhipTrackerComponentBase : public UActorComponent {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FBulletWhipTrackerData> WhipTrackerData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
	USceneComponent* CachedPassByPawn;
    
public:
	UBulletWhipTrackerComponentBase();
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void UpdateVelocity(FVector CurrentVelocity);
    
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void Reset(FVector StartLocationIn);
    
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void Disable();
    
};

