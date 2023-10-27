// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterBodyPartData.h"
#include "Animation/FortMontageLookupTable.h"
#include "CustomSkinColorSwatch.h"
#include "CustomHairColorSwatch.h"
#include "CustomCharacterHeadData.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterHeadData : public UCustomCharacterBodyPartData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Animation")
	TSoftObjectPtr<UFortMontageLookupTable> RootSkeletonDefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Animation")
	TSoftObjectPtr<UFortMontageLookupTable> RootSkeletonOverrideMontageLookupTable;
	
	UPROPERTY(EditAnywhere, Category = "Material Tweaks")
	TSoftObjectPtr<UCustomSkinColorSwatch> SkinColorSwatch;

	UPROPERTY(EditAnywhere, Category = "Material Tweaks")
	TSoftObjectPtr<UCustomHairColorSwatch> HairColorSwatch;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
	TArray<FName> CapMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
	TArray<FName> HelmetMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
	TArray<FName> MaskMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
	TArray<FName> HatMorphTargets;
};