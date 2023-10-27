#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortUIFeedbackBank.generated.h"

USTRUCT(BlueprintType)
struct FFortUIFeedback {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* Audio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLooping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOut;
};
USTRUCT(BlueprintType)
struct FFortUIFeedbackBlueprintOnly : public FFortUIFeedback {
	GENERATED_BODY()
public:
};

UCLASS(Blueprintable)
class UFortUIFeedbackBank : public UDataAsset {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TMap<FName, FFortUIFeedback> FeedbackEvents;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bIsAthenaData;
    
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	//TMap<FName, FFortUIFeedbackBlueprintOnly> BankDefinedFeedbackEvents;
};

