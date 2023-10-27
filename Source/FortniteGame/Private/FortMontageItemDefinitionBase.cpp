#include "FortMontageItemDefinitionBase.h"

bool UFortMontageItemDefinitionBase::ShouldPlayRandomSectionByName() const {
    return false;
}

void UFortMontageItemDefinitionBase::PreviewInPIE() {
}

FName UFortMontageItemDefinitionBase::PickRandomSectionByName() const {
    return NAME_None;
}

UAnimMontage* UFortMontageItemDefinitionBase::GetAnimationHardReference(TEnumAsByte<EFortCustomBodyType::Type> BodyType, TEnumAsByte<EFortCustomGender::Type> Gender) const {
    return NULL;
}

TSoftObjectPtr<UAnimMontage> UFortMontageItemDefinitionBase::GetAnimation(TEnumAsByte<EFortCustomBodyType::Type> BodyType, TEnumAsByte<EFortCustomGender::Type> Gender) const {
    return NULL;
}

UFortMontageItemDefinitionBase::UFortMontageItemDefinitionBase() {
    this->PreviewLoops = 1;
    this->PreviewLength = 0.00f;
    this->EmoteCooldownSecs = 3.00f;
    this->bMontageContainsFacialAnimation = false;
    this->bPlayRandomSection = false;
    this->bSwitchToHarvestingToolOnUse = false;
    this->bHolsterWeapon = false;
}

