#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "FortTokenToAttributeTable.generated.h"

USTRUCT(BlueprintType)
struct FTokenAttributePair {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTag Token;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayAttribute Attribute;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortTokenToAttributeTable : public UDataAsset {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FTokenAttributePair> TokenToAttributeList;
};

