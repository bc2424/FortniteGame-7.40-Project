#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "FortMusicAsset.h"
#include "FortMusicCombatBank.generated.h"

class UFortMusicAsset;

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortMusicCombatBank : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortMusicAsset* Assets[4];
    
	UFortMusicCombatBank();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UFortMusicAsset* GetAssetFromCombatIntensity(TEnumAsByte<EFortMusicCombatIntensity::Type> Intensity) const;
    
};

