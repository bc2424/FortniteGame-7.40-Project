// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPersistableItemDefinition.h"
#include "FortProfileItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortProfileItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()
public:
	UFortProfileItemDefinition()
	{
		ItemType = EFortItemType::Profile;
	}
protected:
	
	UPROPERTY()
	bool bCanBeFavorite;

	UPROPERTY()
	bool bCanBeMarkedSeen;

	UPROPERTY()
	FString GrantToProfileType;
};