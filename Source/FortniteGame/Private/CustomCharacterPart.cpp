#include "CustomCharacterPart.h"

USkeletalMesh* UCustomCharacterPart::GetSkeletalMesh() const {
    return NULL;
}

TMap<int32, UMaterialInterface*> UCustomCharacterPart::GetMaterialOverridesByIndex() {
    return TMap<int32, UMaterialInterface*>();
}

UCustomCharacterPart::UCustomCharacterPart() {
    this->GenderPermitted = EFortCustomGender::Male;
    this->BodyTypesPermitted = EFortCustomBodyType::All;
    this->CharacterPartType = EFortCustomPartType::Head;
    this->bGameplayRelevantCosmeticPart = false;
    this->bAttachToSocket = true;
    this->AdditionalData = NULL;
    this->FrontEndBackPreviewRotationOffset = 0.00f;
    this->bSinglePieceMesh = false;
    this->bSupportsColorSwatches = true;
    this->bAllowStaticRenderPath = false;
    this->MaterialOverrideFlags = 0;
}

