#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Sound/SoundCue.h"
#include "FortPackPersonality.generated.h"

UCLASS(BlueprintType)
class UFortPackPersonality : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Store")
    USoundCue* TickleVOSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Store")
    USoundCue* TickleSFXSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Store")
    USoundCue* XRayVOSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Store")
    USoundCue* HoverVOSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Store")
    USoundCue* BuySFXSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generic")
    USoundCue* OpenGenericVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generic")
    USoundCue* OpenGenericSFX_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Silver")
    USoundCue* UpgradeSilverVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Silver")
    USoundCue* UpgradeSilverSFX_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Silver")
    USoundCue* OpenSilverVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Silver")
    USoundCue* OpenSilverSFX_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gold")
    USoundCue* UpgradeGoldVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gold")
    USoundCue* UpgradeGoldSFX_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gold")
    USoundCue* OpenGoldVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gold")
    USoundCue* OpenGoldSFX_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetGenericVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetAxeVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetBaseballBatVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetGardenHoeVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetGardenRakeVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetHockeyStickVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetPickAxeVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetPitchforkVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetScytheVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetSledgehammerVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greets")
    USoundCue* GreetSwordVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound")
    USoundCue* PreHitVO_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Music")
    USoundCue* DropMusic_Sound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Music")
    USoundCue* OpenMusic_Sound;
};
