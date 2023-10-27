// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortWorldItemDefinition.h"
#include "Customization/CustomCharacterPart.h"
#include "Animation/FortAnimInstance.h"
#include "Abilities/FortAbilitySet.h"
#include "FortHeroType.h"
#include "Abilities/FortGameplayAbility.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "Sound/FortFootstepAudioBank.h"
#include "FortGadgetItemDefinition.generated.h"

class UFortAbilitySet;

UCLASS()
class FORTNITEGAME_API UFortGadgetItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
protected:
	UFortGadgetItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Gadget Priority")
	int32 GadgetPriority;

	UPROPERTY(EditAnywhere, Category = "Gadget - Ability Sets")
	bool bDestroyGadgetWhenTrackedAttributesIsZero = true;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	bool bHasChargeUp;

	UPROPERTY(EditAnywhere, Category = "Functionality")
	bool bDropAllOnEquip;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	bool bCanChangePreviewImageDuringGame;

	UPROPERTY(EditAnywhere, Category = "Gadget - Cosmetic")
	TArray<UCustomCharacterPart*> CharacterParts;

	UPROPERTY(EditAnywhere, Category = "Gadget - Animation")
	TSoftClassPtr<UFortAnimInstance> AnimBPOverride;

	UPROPERTY(EditAnywhere, Category = "Gadget - Animation")
	TSoftObjectPtr<UFortFootstepAudioBank> FootstepBankOverride;

	UPROPERTY(EditAnywhere, Category = "Gadget - Ability Sets")
	TSoftObjectPtr<UFortAbilitySet> AbilitySet;

	UPROPERTY(EditAnywhere, Category = "Gadget - Ability Sets")
	TSoftClassPtr<UAttributeSet> AttributeSet;

	//UPROPERTY(EditAnywhere, Category = "Gadget - Ability Sets")
	//FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditAnywhere, Category = "Gadget - Ability Sets")
	TArray<FGameplayAttribute> TrackedAttributes;

	UPROPERTY(EditAnywhere, Category = "Gadget - Tracked Attributes - Destroy FX")
	TSoftObjectPtr<UParticleSystem> OnDestroyParticleSystem;

	UPROPERTY(EditAnywhere, Category = "Gadget - Tracked Attributes - Destroy FX")
	TSoftObjectPtr<USoundBase> OnDestroySound;

	UPROPERTY(EditAnywhere, Category = "Gadget - Tracked Attributes - Destroy FX")
	 FName OnDestroyAttachToSocketName;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	TSoftClassPtr<UFortGameplayAbility> GameplayAbility;

	UPROPERTY(EditAnywhere, Category = "Functionality")
	 FGameplayTagContainer HUDVisibilityTags;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	TSoftObjectPtr<UFortWeaponItemDefinition> WeaponItemDefinition;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	bool bValidForLastEquipped;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	 FGameplayAttribute LevelAttribute;

	UPROPERTY(EditAnywhere, Category = "Gadget - Deco Ability")
	 FDataTableRowHandle DamageStatHandle;

	UPROPERTY(EditAnywhere, Category = "Gadget - Homebase Node")
	 FString NodeId;
};

