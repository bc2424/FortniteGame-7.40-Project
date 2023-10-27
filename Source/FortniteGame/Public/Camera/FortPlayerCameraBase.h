// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "GameplayAbilitySpec.h"
#include "Camera/PlayerCameraManager.h"
#include "FortPlayerCameraBase.generated.h"

UCLASS()
class FORTNITEGAME_API AFortPlayerCameraBase : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FActiveFortCamera> CameraBlendStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortCameraInstanceEntry> CameraInstances;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> CurrentAbilitySpecifiedCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayAbilitySpecHandle AbilitySpecForCameraClassRequest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> Base3PClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> Targeting3PClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> OverrideCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCinematicCamera> CinematicCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> DBNOCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> DeathCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> SkydiveGlideCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> SkydiveDiveCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> SkydiveParachuteCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFortCameraMode> HoverboardCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortCameraPrototype> CameraPrototypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class APostProcessVolume* ZoomPostProcessVolume;
};
