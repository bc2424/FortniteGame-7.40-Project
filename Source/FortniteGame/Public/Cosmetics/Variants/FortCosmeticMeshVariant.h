// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariantTypes.h"
#include "FortCosmeticVariant.h"
#include "FortCosmeticMeshVariant.generated.h"


USTRUCT()
struct FMeshVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMeshVariant> VariantMeshes;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialParamterDef> VariantMaterialParams;

	UPROPERTY(EditAnywhere)
	TArray<FVariantParticleSystemInitializerData> InitialParticleSystemData;

	UPROPERTY(EditAnywhere)
	TArray<FParticleVariant> VariantParticles;

	UPROPERTY(EditAnywhere)
	TArray<FParticleParamterVariant> VariantParticleParams;

	UPROPERTY(EditAnywhere)
	TArray<FSocketTransformVariant> SocketTransforms;

	UPROPERTY(EditAnywhere)
	TArray<FSoundVariant> VariantSounds;
};

UCLASS()
class UFortCosmeticMeshVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
	TArray<FMeshVariantDef> MeshOptions;                                   
};