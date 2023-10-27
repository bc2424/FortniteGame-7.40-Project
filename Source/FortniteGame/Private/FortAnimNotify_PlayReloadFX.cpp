#include "FortAnimNotify_PlayReloadFX.h"

void UFortAnimNotify_PlayReloadFX::SetReloadStage(TEnumAsByte<EFortReloadFXState::Type> InReloadStage) const {
}

UFortAnimNotify_PlayReloadFX::UFortAnimNotify_PlayReloadFX() {
    this->ReloadStage = EFortReloadFXState::ReloadStart;
}

