#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "EFortReloadFXState.h"
#include "FortAnimNotify_PlayReloadFX.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class FORTNITEGAME_API UFortAnimNotify_PlayReloadFX : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFortReloadFXState::Type> ReloadStage;
    
    UFortAnimNotify_PlayReloadFX();
private:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetReloadStage(TEnumAsByte<EFortReloadFXState::Type> InReloadStage) const;
    
};

