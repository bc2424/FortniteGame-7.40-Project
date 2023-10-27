#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "FortScoreStylingData.generated.h"

USTRUCT(BlueprintType)
struct FFortScoreStylingInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText Name;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortMultiSizeBrush Icon;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor Color;
};
UCLASS(Blueprintable)
class UFortScoreStylingData : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortScoreStylingInfo ScoreStyles[6];
    
	UFortScoreStylingData();
	UFUNCTION(BlueprintCallable)
	static bool GetScoreStylingData(TEnumAsByte<EFortUIScoreType::Type> Rarity, FFortScoreStylingInfo& ScoreStylingInfo);
    
};

