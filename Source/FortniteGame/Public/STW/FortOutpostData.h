#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/CurveTable.h"
#include "FortOutpostData.generated.h"

class UDataTable;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FOutpostBuildingData {
	GENERATED_BODY()
public:
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//	TSoftObjectPtr<UFortOutpostItemDefinition> ItemDefinition;
};

USTRUCT(BlueprintType)
struct FCraftingTableBuildingData : public FOutpostBuildingData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UDataTable* ActivationCostData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<UGameplayEffect> ActivationEffect;
};

class UDataTable;
class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FFabricatorBuildingData : public FOutpostBuildingData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<TSoftObjectPtr<UFortWorldItemDefinition>> AlwaysAvailableFabricationItems;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UDataTable* DefaultIngredientDisintergrationData;
    
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//	TArray<FOutpostFabricatorPerTheaterData> IngredientDisintergrationPerTheaterData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float FabricationDuration;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 DisintegrationToFabricationRatio;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 QuantumGooProductionTime;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<int32> QuantumGooCapacityPerLevel;
};

USTRUCT(BlueprintType)
struct FHarvestingOptimizerBuildingData : public FOutpostBuildingData {
	GENERATED_BODY()
public:
};

USTRUCT(BlueprintType)
struct FStorageVaultBuildingData : public FOutpostBuildingData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<int32> ItemCapacityPerLevel;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FOutpostPOSTBoost {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCurveTableRowHandle PlayerStructureHealthModPerPOSTLevel;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FOutpostPrestigeEffects {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<TSubclassOf<UGameplayEffect>> EnemyPrestigeEffect;
};

USTRUCT(BlueprintType)
struct FOutpostUpgradeAndPrestigeBuildingData : public FOutpostBuildingData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 MaxPrestigeLevel;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UDataTable* DefaultOutpostBuildingUpgradeData;
    
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//	TArray<FOutpostUpgradesPerTheaterData> PerTheaterOutpostBuildingUpgradeData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FOutpostPrestigeEffects DefaultPrestigeData;
    
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//	TArray<FOutpostPrestigeEffectsPerTheater> PrestigePerTheaterData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FOutpostPOSTBoost DefaultPOSTData;
    
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//	TArray<FOutpostPOSTPerTheaterData> POSTPerTheaterData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<UGameplayEffect> POSTBuildingGameplayEffectClass;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortOutpostData : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 StructureLimitNotificationThreshold;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FOutpostBuildingData StormShieldData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCraftingTableBuildingData CraftingTableData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFabricatorBuildingData FabricatorData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FHarvestingOptimizerBuildingData HarvestingOptimizerData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FStorageVaultBuildingData StorageVaultData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FOutpostUpgradeAndPrestigeBuildingData OutpostUpgradeAndPrestigeData;
    
	UFortOutpostData();
};

