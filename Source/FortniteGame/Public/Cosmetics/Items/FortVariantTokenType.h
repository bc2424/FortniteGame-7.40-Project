// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortAccountItemDefinition.h"
#include "FortniteGame.h"
#include "AthenaCosmeticItemDefinition.h"
#include "FortVariantTokenType.generated.h"

UCLASS()
class FORTNITEGAME_API UFortVariantTokenType : public UFortAccountItemDefinition
{
	GENERATED_BODY()
protected:
	UFortVariantTokenType();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemProfileType ProfileType = EItemProfileType::Athena; 

	UPROPERTY(EditAnywhere)
	 UFortItemDefinition* Cosmetic_item;

	UPROPERTY(EditAnywhere)
	 FGameplayTag VariantChanelTag;

	UPROPERTY(EditAnywhere)
	 FGameplayTag VariantNameTag;

	UPROPERTY(EditAnywhere)
	TArray<FCosmeticVariantInfo> VariantPreviewOverrides;

	UPROPERTY(EditAnywhere)
	bool bAutoEquipVariant = true;

	UPROPERTY(EditAnywhere)
	bool bMarkItemUnseen = true;

	UPROPERTY(EditAnywhere)
	bool bCreateGiftbox;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("CosmeticVariantToken", GetFName());
	}
};
