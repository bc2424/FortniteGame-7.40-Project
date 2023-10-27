// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "Items/FortItemDefinition.h"
#include "FortPersistentResourceItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortPersistentResourceItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()
	UFortPersistentResourceItemDefinition();
protected:
	UPROPERTY(EditAnywhere)
	bool bIsEventItem;
};
