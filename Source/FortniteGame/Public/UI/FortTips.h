// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTips.generated.h"

UCLASS()
class FORTNITEGAME_API UFortTips : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Tip")
	TArray<FText> Tips;

protected:
	UPROPERTY(EditAnywhere, Category = "Platform")
	bool DisplayOnPlatformPC;

	UPROPERTY(EditAnywhere, Category = "Platform")
	bool DisplayOnPlatformXbox;

	UPROPERTY(EditAnywhere, Category = "Platform")
	bool DisplayOnPlatformPS4;

	UPROPERTY(EditAnywhere, Category = "Platform")
	bool DisplayOnPlatformSwitch;

	UPROPERTY(EditAnywhere, Category = "Platform")
	bool DisplayOnPlatformMobile;
};
