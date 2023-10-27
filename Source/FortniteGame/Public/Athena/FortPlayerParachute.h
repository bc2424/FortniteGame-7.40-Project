// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.



#pragma once


#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Pawns/FortPlayerPawn.h"
#include "Sound/SoundBase.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "FortPlayerParachute.generated.h"

UCLASS()
class FORTNITEGAME_API AFortPlayerParachute : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Transient)
	TSoftObjectPtr<USoundBase> GliderOpenSoundFromDef;

	UPROPERTY(EditAnywhere, Transient)
	class USoundBase* CurrentGliderOpenSound;

	UPROPERTY(EditAnywhere, Transient)
	TWeakObjectPtr<UAudioComponent> CurrentGliderOpenAudioComponent;

	UPROPERTY(EditAnywhere, Transient)
	TSoftObjectPtr<USoundBase> GliderCloseSoundFromDef;

	UPROPERTY(EditAnywhere, Transient)
	class USoundBase* CurrentGliderCloseSound;

	UPROPERTY(EditAnywhere, Transient)
	TWeakObjectPtr<UAudioComponent> CurrentGliderCloseAudioComponent;

	UPROPERTY(EditAnywhere)
	class AFortPlayerPawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	class UAthenaGliderItemDefinition* ParachuteItemDef;

	UPROPERTY(EditAnywhere)
	float ParachuteHiddenAnimFinishTime;

	UPROPERTY(EditAnywhere, Transient)
	bool bGliderFullyDeployed;

	UPROPERTY(EditAnywhere)
	bool bChuteOpened;

	UPROPERTY(EditAnywhere)
	bool bIsFrontEndPreview;

	UPROPERTY(EditAnywhere, Transient)
	bool bParachuteVisible;

	UPROPERTY(EditAnywhere, Transient)
	bool bActivateTrailOnRationalMovement;

	UPROPERTY(EditAnywhere, Transient)
	struct FRotator LastRotationalMovement;

	UPROPERTY(EditAnywhere)
	FName ParachuteTrailParameterName;

	UPROPERTY(EditAnywhere)
	bool IsCosmeticPreview;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponentBudgeted* ParachuteMesh;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* TrailParticles;
};