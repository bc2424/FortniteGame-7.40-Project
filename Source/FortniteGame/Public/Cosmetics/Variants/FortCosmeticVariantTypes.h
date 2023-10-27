// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTags.h"
#include "Items/FortItemDefinition.h"
#include "FortAccountItemDefinition.h"
#include "Customization/CustomCharacterPart.h"
#include "FortCosmeticVariantTypes.generated.h"

USTRUCT()
struct FORTNITEGAME_API FMaterialParamName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FName ParamName;
};

UCLASS(DefaultToInstanced, EditInlineNew)
class UVariantTypeBase : public UObject
{
	GENERATED_BODY()
public:
};

USTRUCT()
struct FMeshVariant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> MeshToSwap;

	UPROPERTY(EditAnywhere)
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> OverrideMesh;                             
};

UCLASS()
class UVariantTypeMeshes : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMeshVariant> VariantMeshes;
};

USTRUCT()
struct FSoundVariant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> SoundToSwap;

	UPROPERTY(EditAnywhere)
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> OverrideSound;
};

UCLASS()
class UVariantTypeSounds : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FSoundVariant> VariantSounds;
};

USTRUCT()
struct FORTNITEGAME_API FMaterialVariants
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterialInterface> MaterialToSwap;

	UPROPERTY(EditAnywhere)
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere)
	FName CascadeMaterialName;

	UPROPERTY(EditAnywhere)
	int32 MaterialOverrideIndex;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

UCLASS()
class UVariantTypeMaterials : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMaterialVariants> VariantMaterials;
};

USTRUCT()
struct FORTNITEGAME_API FMaterialTextureVariant : public FMaterialParamName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture> Value;
};

USTRUCT()
struct FORTNITEGAME_API FMaterialFloatVariant : public FMaterialParamName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float Value;
};

USTRUCT()
struct FORTNITEGAME_API FMaterialVectorVariant : public FMaterialParamName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FLinearColor Value;
};

USTRUCT()
struct FMaterialParamterDef
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterialInterface> MaterialToAlter;

	UPROPERTY(EditAnywhere)
	FName CascadeMaterialName;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialTextureVariant> TextureParams;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialFloatVariant> FloatParams;
};

UCLASS()
class UVariantTypeMaterialParams : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMaterialParamterDef> VariantMaterialParams;
};

USTRUCT()
struct FVariantParticleSystemInitializerData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FName ParticleComponentName;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UParticleSystem> ParticleSystem;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> MeshToBindTO;

	UPROPERTY(EditAnywhere)
	FName AttachSocketName;

	UPROPERTY(EditAnywhere)
	EAttachmentRule LocationRule;

	UPROPERTY(EditAnywhere)
	EAttachmentRule RotationRule;

	UPROPERTY(EditAnywhere)
	EAttachmentRule ScaleRule;

	UPROPERTY(EditAnywhere)
	bool bWeldSimulatedBodies;
};

UCLASS()
class UVariantTypeInitialParticleSystemData : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FVariantParticleSystemInitializerData> VariantInitialParticleSystemData;
};

USTRUCT()
struct FParticleVariant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UParticleSystem> ParticleSystemToAlter;

	UPROPERTY(EditAnywhere)
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UParticleSystem> OverrideParticleSystem;
};


UCLASS()
class UVariantTypeParticles : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FParticleVariant> VariantParticles;
};

USTRUCT()
struct FVectorParamVariant : public FMaterialParamName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FVector Value;
};

USTRUCT()
struct FParticleParamterVariant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere)
	TArray<FVectorParamVariant>  VectorParams;

	UPROPERTY(EditAnywhere)
	TArray<FMaterialFloatVariant> FloatParams;
};

UCLASS()
class UVariantTypeParticleParams : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FParticleParamterVariant> VariantParticleParams;
};

USTRUCT()
struct FSocketTransformVariant
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FName SourceSocketName;

	UPROPERTY(EditAnywhere)
	FName  OverridSocketName;
};

UCLASS()
class UVariantTypeSocketTransforms : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FSocketTransformVariant> VariantSocketTransforms;
};

UCLASS()
class UVariantTypeCharacterParts : public UVariantTypeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UCustomCharacterPart>> VariantParts;
};