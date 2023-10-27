#pragma once
#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "FortGenericRecord.h"
#include "BuildingActor.h"
#include "FortDeployableBaseRecord.generated.h"

USTRUCT(BlueprintType)
struct FFortActorRecord {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGuid ActorGuid;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortBuildingPersistentState::Type> ActorState;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<ABuildingActor> ActorClass;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FTransform ActorTransform;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bSpawnedActor;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<uint8> ActorData;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortDeployableBaseRecord : public UFortGenericRecord {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortActorRecord> Actors;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	uint8 bNeedsFullActorSave: 1;
    
public:
	UFortDeployableBaseRecord();
};

