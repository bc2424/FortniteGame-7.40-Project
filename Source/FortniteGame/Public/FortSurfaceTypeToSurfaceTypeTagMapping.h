#pragma once
#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Engine/DataAsset.h"
#include "FortSurfaceTypeToSurfaceTypeTagMapping.generated.h"


USTRUCT(BlueprintType)
struct FFortSurfaceTypeToSurfaceTypeTag {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortFootstepSurfaceType FootSurfaceType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EPhysicalSurface> SurfaceType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTag SurfaceTypeTag;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bAllowsSurfaceRetriggerOfEvents;
};

UCLASS(Blueprintable)
class UFortSurfaceTypeToSurfaceTypeTagMapping : public UDataAsset {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortSurfaceTypeToSurfaceTypeTag> TypeToTagMapping;
};

