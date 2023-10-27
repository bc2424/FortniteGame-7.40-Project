// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItem.h"
#include "FortAccountItemDefinition.h"
#include "FortCharacter.generated.h"

UCLASS()
class FORTNITEGAME_API UFortCharacter : public UFortAccountItem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FString Squad_id;

	UPROPERTY(BlueprintReadOnly)
	int32 Squad_slot_idx;
};
