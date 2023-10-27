// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWorldItemDefinition.h"
#include "FortniteGame.h"
#include "FortResourceItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortResourceItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
	UFortResourceItemDefinition()
	{
		ItemType = EFortItemType::AccountResource;
	}
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EFortResourceType::Type> ResourceType;
};