// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/GameEngine.h"
#include "FortEngine.generated.h"

UCLASS(Blueprintable, NonTransient)
class FORTNITEGAME_API UFortEngine : public UGameEngine {
	GENERATED_BODY()
public:
	UFortEngine();
private:
	UFUNCTION(BlueprintCallable, Exec)
	void StartFortBench(const FString& ReplayName);
    
};





