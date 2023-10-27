#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "GameplayTagContainer.h"
#include "FortTagUIDataLookupTable.generated.h"


USTRUCT(BlueprintType)
struct FFortTagUIData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTag Tag;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortMultiSizeBrush Icon;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText DisplayName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText Description;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortTagUIDataLookupTable : public UDataAsset {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTagUIData> TagUIDataList;
};

