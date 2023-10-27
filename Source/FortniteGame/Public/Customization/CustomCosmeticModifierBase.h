// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Pawns/FortPlayerPawn.h"
#include "CustomCosmeticModifierBase.generated.h"

UCLASS()
class FORTNITEGAME_API ACustomCosmeticModifierBase : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> FortPlayerPawnPtr;
};