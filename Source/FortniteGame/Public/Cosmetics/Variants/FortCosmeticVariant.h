// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemDefinition.h"
#include "FortCosmeticVariant.generated.h"

USTRUCT()
struct FORTNITEGAME_API FBaseVariantDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	bool bStartUnlocked = true;

	UPROPERTY(EditAnywhere)
	bool bIsDefault;

	UPROPERTY(EditAnywhere)
	bool bHideIfNotOwned;

	UPROPERTY(EditAnywhere)
	FGameplayTag CustomizationVariantTag;

	UPROPERTY(EditAnywhere)
	FText VariantName;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> PreviewImage;

	UPROPERTY(EditAnywhere)
	FText UnlockRequirements;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMcpItemDefinitionBase> UnlockingItemDef;
};

UCLASS(DefaultToInstanced, EditInlineNew)
class FORTNITEGAME_API UFortCosmeticVariant : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
		FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, Category = "Display Data")
		FText VariantChannelName;

	UPROPERTY(EditAnywhere, Category = "Display Data")
		FGameplayTag ActiveVariantTag;
};

UCLASS()
class FORTNITEGAME_API UFortCosmeticVariantBackedByArray : public UFortCosmeticVariant
{
	GENERATED_BODY()
public:
};

