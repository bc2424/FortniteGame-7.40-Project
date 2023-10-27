// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortWeaponRanged.h"
#include "FortGameplayAbility_RangedWeapon.generated.h"

UCLASS(Blueprintable)
class UFortGameplayAbility_RangedWeapon : public UFortGameplayAbility {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float FiringNoiseRange;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	AFortWeaponRanged* CurrentWeapon;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer WeaponFireCue;
    
	UFortGameplayAbility_RangedWeapon() {
		this->FiringNoiseRange = 2048.00f;
		this->CurrentWeapon = NULL;
	}
};
