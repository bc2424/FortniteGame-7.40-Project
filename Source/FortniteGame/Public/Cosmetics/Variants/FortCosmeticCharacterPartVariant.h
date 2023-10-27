// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariant.h"
#include "Items/FortItemDefinition.h"
#include "FortCosmeticVariantTypes.h"
#include "Customization/CustomCharacterPart.h"
#include "FortCosmeticCharacterPartVariant.generated.h"

USTRUCT()
struct FPartVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UCustomCharacterPart>> VariantParts;

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

	UPROPERTY(EditAnywhere)
	TArray<FSocketTransformVariant> SocketTransforms;
	
};

UCLASS()
class UFortCosmeticCharacterPartVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Cosmetic Variant")
	TArray<FPartVariantDef> PartOptions;
};