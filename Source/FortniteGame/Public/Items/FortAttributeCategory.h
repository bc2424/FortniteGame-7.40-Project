// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "AttributeSet.h"
#include "FortAttributeCategory.generated.h"

USTRUCT(BlueprintType)
struct FMyFortCategoryData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 FText CategoryName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 FGameplayTag TooltipTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 FGameplayTagContainer ModifiedTagContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsCore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FGameplayAttribute> Attributes;                                     
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortAttributeCategory : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Data")
	TArray<FMyFortCategoryData> Categories;
};