#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "FortAIPawn.h"
#include "FortAIPawnVariant.generated.h"

class AFortAIPawn;

USTRUCT(BlueprintType)
struct FFortAIPawnVariantDefinition {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<AFortAIPawn> PawnClass;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCurveTableRowHandle VariantWeightCurve;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	float CurrentWeight;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery RequiredTagsQuery;
};

UCLASS(Abstract, Blueprintable)
class UFortAIPawnVariant : public UObject {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<TSubclassOf<AFortAIPawn>> PawnClasses;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAIPawnVariantDefinition> PawnVariantDefinitions;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 MinPlayersToSpawnVariant;
    
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FDataTableRowHandle SpawnPointValueHandle;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 CachedSpawnPointValue;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float EncounterExpectedLifespan;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 VersionNum;
};

