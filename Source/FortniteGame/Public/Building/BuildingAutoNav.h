// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingSMActor.h"
#include "BuildingAutoNav.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class ABuildingAutoNav : public ABuildingSMActor {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bAutoAssignNavProperties: 1;
	ABuildingAutoNav()
	{
		this->bAutoAssignNavProperties = true;
	}
};

