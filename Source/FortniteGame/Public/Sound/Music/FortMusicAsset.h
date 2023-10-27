#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "FortMusicAsset.generated.h"

USTRUCT(BlueprintType)
struct FFortMusicSection {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	USoundBase* Sound;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float FadeInTime;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float FadeOutTime;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float InitialOffset;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Duration;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortMusicAsset : public UPrimaryDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortMusicSection Sections[3];
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Priority;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortMusicSectionStopBehavior StopBehavior;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bIsStinger;
};

