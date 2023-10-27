#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "FortDeployableBaseSkillTreeUnlocks.generated.h"

USTRUCT(BlueprintType)
struct FFortTaggedUnlockBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag RequiredTag;
};

USTRUCT(BlueprintType)
struct FFortTaggedDeployableBasePlotExpansionUnlock : public FFortTaggedUnlockBase {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FIntVector CellExpansionVector;
};


USTRUCT(BlueprintType)
struct FFortTaggedDeployableBaseLootUnlock : public FFortTaggedUnlockBase {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName LootTierGroup;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortDeployableBaseSkillTreeUnlocks : public UDataAsset {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTaggedDeployableBasePlotExpansionUnlock> PlotSizeUnlocks;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTaggedDeployableBaseLootUnlock> NeighborhoodLootGrantUnlocks;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTaggedDeployableBaseLootUnlock> CombatZoneStartLootGrantUnlocks;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTaggedDeployableBaseLootUnlock> CombatZoneWaveCompleteLootGrantUnlocks;
};

