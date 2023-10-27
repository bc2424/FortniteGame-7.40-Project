// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "FortniteGame.h"
#include "FortFootstepAudioBank.generated.h"


USTRUCT()
struct FFortFootstepAudioData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundBase* SoundAssets[8];

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundBase* SoundAssetsAbove[8];

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundBase* SoundAssetsBelow[8];

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundAttenuation* SoundAttenuation;

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundAttenuation* SoundAttenuationAbove;

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundAttenuation* SoundAttenuationBelow;

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	class USoundAttenuation* SoundAttenuationAboveOrBelowAndVisible;

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	float VolumeMultiplier;
};

UCLASS()
class FORTNITEGAME_API UFortFootstepAudioBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	FFortFootstepAudioData FootstepData1P[7];

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	FFortFootstepAudioData FootstepData3P[7];

	UPROPERTY(EditAnywhere, Category = "FootstepAudio")
	EFortFootstepSurfaceType PhysicalSurfaceMappings[0x1A];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootstepAudio")
	float TeammateVolumeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootstepAudio")
	float MaxFootstepDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootstepAudio")
	float VerticalPitchMaxBelow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootstepAudio")
	float VerticalPitchMaxAbove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootstepAudio")
	float VerticalPitchTileRange;
};
