// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTooltip.generated.h"

UCLASS()
class UFortTooltip : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	 FText Description;
};