// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterBackpackData.h"
#include "CustomCharacterCharmData.h"
#include "CustomCharacterFaceData.h"
#include "CustomCharacterHatData.h"
#include "CustomCharacterHeadData.h"
#include "CustomCharacterPartData.h"
#include "Engine/DataAsset.h"
#include "Animation/FortMontageLookupTable.h"
#include "CustomCharacterPartModifier.h"
#include "FortniteGame.h"
#include "CustomCharacterPart.generated.h"

USTRUCT(BlueprintType)
struct FCustomPartMaterialOverrideData
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere)
		int MaterialOverrideIndex;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

USTRUCT(BlueprintType)
struct FCustomPartScalarParameter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		int MaterialIndexForScalarParameter;

	UPROPERTY(EditAnywhere)
		FName ScalarParameterNameForMaterial;

	UPROPERTY(EditAnywhere)
		float ScalarOverride;
};

USTRUCT(BlueprintType)
struct FCustomPartTextureParameter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		int MaterialIndexForTextureParameter;

	UPROPERTY(EditAnywhere)
		FName TextureParameterNameForMaterial;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UTexture> TextureOverride;
};

USTRUCT(BlueprintType)
struct FCustomPartVectorParameter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		int MaterialIndexForVectorParameter;

	UPROPERTY(EditAnywhere)
		FName VectorParameterNameForMaterial;

	UPROPERTY(EditAnywhere)
		FLinearColor VectorOverride;
};


UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterPart : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Character Part")
		EFortCustomGender GenderPermitted;
	
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Character Part")
		EFortCustomBodyType BodyTypesPermitted;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, AssetRegistrySearchable, Category = "Character Part")
		EFortCustomPartType CharacterPartType;

	UPROPERTY(EditAnywhere, Category = "Character Part")
	FGameplayTagContainer PartTypeTags;
	
	UPROPERTY(EditAnywhere, Category = "Character Part")
		FGameplayTagContainer DisallowedCosmeticTags;

	UPROPERTY(EditAnywhere, Category = "Character Part|Advanced")
		bool bGameplayRelevantCosmeticPart;

	UPROPERTY(EditAnywhere, Category = "Character Part")
		bool bAttachToSocket = true;

	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		TSoftClassPtr<ACustomCharacterPartModifier> PartModifierBlueprint;

	UPROPERTY(VisibleAnywhere, Instanced, Category = "Character Part|Art", meta=(ShowInnerProperties))
		class UCustomCharacterPartData* AdditionalData;

	UPROPERTY(EditAnywhere, Category = "Character Part|Animation")
		TSoftObjectPtr<UFortMontageLookupTable> DefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Character Part|Animation")
		TSoftObjectPtr<UFortMontageLookupTable> OverrideMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Character Part|Animation")
		TSoftObjectPtr<UAnimMontage> FrontendAnimMontageIdleOverride;

	UPROPERTY(EditAnywhere, Category = "Character Part|Animation")
		float FrontEndBackPreviewRotationOffset;
	
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Character Part|Art", BlueprintReadWrite)
		TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, AssetRegistrySearchable, Category = "Character Part|Art")
		TArray<TSoftObjectPtr<USkeletalMesh>> MasterSkeletalMeshes;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Character Part|Art")
		bool  bSinglePieceMesh;

	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		bool  bSupportsColorSwatches;

	UPROPERTY(EditAnywhere, Category = "Character Part|Animation")
		bool  bAllowStaticRenderPath;

	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		TArray<FCustomPartMaterialOverrideData> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		TArray< FCustomPartTextureParameter> TextureParameters;

	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		TArray<FCustomPartScalarParameter> ScalarParameters;

	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		TArray<FCustomPartVectorParameter> VectorParameters;
	
	UPROPERTY(EditAnywhere, Category = "Character Part|Art")
		int32 MaterialOverrideFlags;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("CharacterPart", GetFName());
	}

#if WITH_EDITOR  
	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) {
		FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
		if (PropertyName == GET_MEMBER_NAME_CHECKED(UCustomCharacterPart, CharacterPartType)) {
			AdditionalData = NewObject<UCustomCharacterPartData>(this, 
				CharacterPartType == EFortCustomPartType::Head ?
					UCustomCharacterHeadData::StaticClass() :
				CharacterPartType == EFortCustomPartType::Body ?
					UCustomCharacterBodyPartData::StaticClass() :
				CharacterPartType == EFortCustomPartType::Hat ?
					UCustomCharacterHatData::StaticClass() :
				CharacterPartType == EFortCustomPartType::Backpack ?
					UCustomCharacterBackpackData::StaticClass() :
				CharacterPartType == EFortCustomPartType::Charm ?
					UCustomCharacterCharmData::StaticClass() :
				CharacterPartType == EFortCustomPartType::Face ?
					UCustomCharacterFaceData::StaticClass() :
					UCustomCharacterBodyPartData::StaticClass()
				);
		}
	}
#endif

};

