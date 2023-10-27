// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Animation/FortTaggedSoundBank.h"
#include "FortPlayerPet.generated.h"

UCLASS()
class FORTNITEGAME_API AFortPlayerPet : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly)
	class UAthenaPetItemDefinition* PetItemDef;

	UPROPERTY(BlueprintReadOnly, Instanced)
	class UAudioComponent* PetAudioComponent;

	UPROPERTY(BlueprintReadOnly)
	bool bIsFrontEndPreview;

	UPROPERTY(EditAnywhere, Instanced)
	class USkeletalMeshComponentBudgeted* PetMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USphereComponent* InteractionCollisionSphere;

	UPROPERTY(Transient)
	TArray<UMaterialInterface*> SavedMaterials;

	UPROPERTY(Transient)
	UFortTaggedSoundBank* SoundBank;
};

