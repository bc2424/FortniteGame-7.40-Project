#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "FortDeployableBaseRecord.h"
#include "FortBuildingInstructions.generated.h"


USTRUCT(BlueprintType)
struct FFortBuildingInstruction {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FFortActorRecord ActorRecord;
};
UCLASS(Blueprintable)
class FORTNITEGAME_API UFortBuildingInstructions : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	TArray<FFortBuildingInstruction> Instructions;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FBoxSphereBounds Bounds;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 NumOfPiecesToSpawnAtOnce;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float TimeBetweenSpawns;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bSetOwnerID;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bUsePlayerBuildAnimations;
    
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FString MapName;
    
public:
	UFortBuildingInstructions()
	{
		this->NumOfPiecesToSpawnAtOnce = 10;
		this->TimeBetweenSpawns = 0.20f;
		this->bSetOwnerID = true;
		this->bUsePlayerBuildAnimations = false;
	}
};

