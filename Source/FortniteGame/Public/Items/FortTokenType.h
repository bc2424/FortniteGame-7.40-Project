// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "Styling/SlateColor.h"
#include "FortScriptedAction.h"
#include "FortniteGame/FortniteGame.h"
#include "FortTokenType.generated.h"

UCLASS()
class FORTNITEGAME_API UFortTokenType : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFortTokenType();
	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AFortScriptedAction> ScriptedAction; 

	UPROPERTY(EditAnywhere)
	FSlateColor NodeTintColour; 

	UPROPERTY(EditAnywhere)
	bool bPercentageRepresentation;

	UPROPERTY(EditAnywhere)
	EItemProfileType ProfileType;

	UPROPERTY(EditAnywhere)
	UClass* ItemPreviewActorClass;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Token", GetFName());
	}
};
