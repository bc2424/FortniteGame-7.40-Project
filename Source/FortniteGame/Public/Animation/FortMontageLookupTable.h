// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "Animation/AnimMontage.h"
#include "FortMontageLookupTable.generated.h"


USTRUCT()
struct FMontageLookupData
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
		//FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
		TSoftObjectPtr<UAnimMontage> AnimMontage = nullptr;
};

UCLASS()
class UFortMontageLookupTable : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Montage Lookup Data", meta = (IgnoreForMemberInitializationTest))
	TArray<FMontageLookupData> MontageLookupDataArray;
};
