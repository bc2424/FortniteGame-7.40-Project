#include "FortAnimNotifyState_SpawnProp.h"

UFortAnimNotifyState_SpawnProp::UFortAnimNotifyState_SpawnProp() {
    this->ActorProp = NULL;
    this->SkeletalMeshProp = NULL;
    this->SkeletalMeshPropAnimation = NULL;
    this->bInheritScale = true;
    this->bAbsoluteScale = false;
    this->bPropAnimLooping = true;
    this->bPrestreamTextures = true;
    this->PrestreamTextureDuration = 5.00f;
    this->StaticMeshProp = NULL;
    this->PropId = 0;
}

