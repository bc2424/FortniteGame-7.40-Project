#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelSaveSpawnable.h"
#include "PropertyOverrideData.h"
#include "FortCreativeVolumeLinkComponent.generated.h"

class AFortVolume;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLinkedVolumeSet, AFortVolume*, PreviousVolume, AFortVolume*, NewVolume);

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortCreativeVolumeLinkComponent : public UActorComponent, public ILevelSaveSpawnable {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FOnLinkedVolumeSet OnLinkedVolumeSet;
    
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	AFortVolume* LinkedVolume;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bShouldFindVolumeAtStart = true;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FPropertyOverrideData LinkedVolumeProperties;
    
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AFortVolume* GetLinkedVolume();
};

