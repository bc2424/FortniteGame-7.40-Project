// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWorldItemDefinition.h"
#include "Items/FortItemDefinition.h"
#include "FortQuestItemDefinition.h"
#include "FortCardPackItemDefinition.h"
#include "FortBadgeItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortBadgeItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
public:
	UFortBadgeItemDefinition()
	{
		ItemType = EFortItemType::Badge;
	}
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText FailedDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor BadgeColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 UIMissionPointsOffset;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle BadgeScoringValuesHandle;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortCardPackItemDefinition> BadgeCardPackReward;

	UPROPERTY(EditAnywhere)
	TArray<FFortItemQuantityPair> ItemRewards;
};
