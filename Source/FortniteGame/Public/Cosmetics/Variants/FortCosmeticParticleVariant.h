// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariantTypes.h"
#include "FortCosmeticVariant.h"
#include "FortCosmeticParticleVariant.generated.h"

USTRUCT()
struct FParticlVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialParamterDef> VariantMaterialParams;

	UPROPERTY(EditAnywhere)
	TArray<FVariantParticleSystemInitializerData> InitalParticelSystemData;

	UPROPERTY(EditAnywhere)
	TArray<FParticleVariant> VariantParticles;

	UPROPERTY(EditAnywhere)
	TArray<FParticleParamterVariant> VariantParticleParams;
};

UCLASS()
class UFortCosmeticParticleVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
	TArray<FParticlVariantDef> ParticleOptions;                                   
};