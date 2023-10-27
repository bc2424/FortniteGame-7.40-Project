// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Athena/FortPlayerParachute.h"
#include "FortniteGame.h"
#include "AthenaGliderItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UAthenaGliderItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaGliderItemDefinition();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EFortGliderType> GliderType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bActivateTrailsOnRotationalMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<AFortPlayerParachute> ParachutePrefabClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> TrailParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> OwnerTrailParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TrailParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<USoundBase> OpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<USoundBase> CloseSound;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaGlider", GetFName());
	}
};
