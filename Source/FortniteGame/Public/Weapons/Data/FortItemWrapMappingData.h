// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Customization/FortItemWrapPreviewActor.h"
#include "FortItemWrapMappingData.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FItemWrapSlotMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FGameplayTagQuery MatchCriteria;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FItemWrapPreviewEntry> PreviewList;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortItemWrapMappingData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FItemWrapSlotMetadata> SlotMetadata;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FItemWrapPreviewEntry> NonSlotPreviewList;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterialInterface> MasterVehicleMaterial;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterialInterface> MasterWeaponMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag DoNotApplyWrapsTag;
};