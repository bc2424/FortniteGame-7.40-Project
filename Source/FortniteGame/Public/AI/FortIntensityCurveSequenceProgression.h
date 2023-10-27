#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortIntensityCurveSequence.h"
#include "FortIntensityCurveSequenceProgression.generated.h"



USTRUCT(BlueprintType)
struct FFortInstensityCurveSequenceProgression {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortIntensityCurveSequence* CurveSequence;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCurveTableRowHandle SelectionWeight;
};

UCLASS(Blueprintable)
class UFortIntensityCurveSequenceProgression : public UDataAsset {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortInstensityCurveSequenceProgression> IntensityCurveSequences;
};

