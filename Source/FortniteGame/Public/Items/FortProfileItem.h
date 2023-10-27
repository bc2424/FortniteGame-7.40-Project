// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPersistableItem.h"
#include "FortProfileItem.generated.h"

UCLASS()
class FORTNITEGAME_API UFortProfileItem : public UFortPersistableItem
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	bool Item_seen;

	UPROPERTY(EditAnywhere)
	bool Favorite;
};