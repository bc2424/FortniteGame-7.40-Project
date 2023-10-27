#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/CurveTable.h"
#include "FortniteGame.h"
#include "TierMeshSets.generated.h"

class UParticleSystem;
class USoundBase;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FMeshSet {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Weight;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortResourceType::Type> ResourceType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bDoNotBlockBuildings: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bDestroyOnPlayerBuildingPlacement: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bNeedsDamageOverlay: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UStaticMesh* BaseMesh;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UParticleSystem* BreakEffect;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UParticleSystem* DeathParticles;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName DeathParticleSocketName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	USoundBase* DeathSound;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UParticleSystem* ConstructedEffect;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UStaticMesh* SearchedMesh;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCurveTableRowHandle SearchSpeed;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float LootNoiseRange;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FVector LootSpawnLocation;
};

USTRUCT(BlueprintType)
struct FTierMeshSets {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 Tier;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FMeshSet> MeshSets;
};