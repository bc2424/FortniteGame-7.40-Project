// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "FortniteGame.h"

#include "CustomCharacterPart.generated.h"
/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UCustomCharacterPart : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFortCustomBodyType> BodyTypesPermitted;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFortCustomPartType>                   CharacterPartType;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class USkeletalMesh>                SkeletalMesh;

	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<class USkeletalMesh>>                MasterSkeletalMeshes;

	UPROPERTY(EditAnywhere, Instanced)
	class UCustomCharacterPartData*                    AdditionalData;
};
