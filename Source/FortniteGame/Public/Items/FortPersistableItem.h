// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPersistableItemDefinition.h"
#include "Items/FortItem.h"
#include "FortPersistableItem.generated.h"

UCLASS()
class UFortPersistableItem : public UFortItem
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UFortPersistableItemDefinition* ItemDefinition;

	UPROPERTY(BlueprintReadOnly)
	FString InstanceId;

	UPROPERTY(BlueprintReadOnly)
	FString TemplateId;

	UPROPERTY(BlueprintReadOnly)
	int32 Quantity;

	UPROPERTY()
	bool bIsLocalOnlyItem;
};

