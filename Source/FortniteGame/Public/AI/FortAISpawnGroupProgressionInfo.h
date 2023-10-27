#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortAISpawnGroupProgressionInfo.generated.h"

class UFortAISpawnGroup;

USTRUCT(BlueprintType)
struct FSpawnGroupProgression {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortAISpawnGroup* SpawnGroup;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortAISpawnGroupProgressionInfo : public UDataAsset {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FSpawnGroupProgression> SpawnGroups;
};

