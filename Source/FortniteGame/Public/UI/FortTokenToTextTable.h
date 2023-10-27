#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortTokenToTextTable.generated.h"

USTRUCT(BlueprintType)
struct FFortTokenContextInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer RequiredContextTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText Text;
};
USTRUCT(BlueprintType)
struct FFortTooltipTokenInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTag Token;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTokenContextInfo> ContextDetails;
	
};
UCLASS(Blueprintable)
class FORTNITEGAME_API UFortTokenToTextTable : public UDataAsset {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTooltipTokenInfo> TokenInfoList;
};

