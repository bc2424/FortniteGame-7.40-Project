// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FortniteGame.h"
#include "Camera/PlayerCameraManager.h"
#include "FortPlayerCameraBase.h"
#include "FortCameraMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FORTNITEGAME_API UFortCameraMode : public UObject
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AFortPlayerCameraBase* PlayerCamera;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TransitionTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TransitionOutTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FViewTargetTransitionParams TransitionParams;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bResetInterpolation;
};
