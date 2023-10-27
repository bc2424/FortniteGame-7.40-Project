#pragma once
#include "CoreMinimal.h"
#include "BuildingTextureData.h"
#include "FortBuildings_Structs.generated.h"

class UParticleSystem;
class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FProxyGameplayCueDamagePhysical {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float ProxyGameplayCueDamagePhysicalMagnitude;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayEffectContextHandle EffectContext;
};

USTRUCT(BlueprintType)
struct FBuildingDuplicationData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UClass* ClassData;
    
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	UBuildingTextureData* TextureData[4];
};


