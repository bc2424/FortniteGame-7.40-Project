// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"
#include "Items/AthenaDanceItemDefinition.h"
#include "Items/AthenaPickaxeItemDefinition.h"
#include "Items/AthenaSeasonItemDefinition.h"
#include "Items/FortItemDefinition.h"
#include "Items/FortCosmeticItemMarkupTable.h"
#include "Items/AthenaBattleBusItemDefinition.h"
#include "Items/AthenaGliderItemDefinition.h"
#include "AthenaMusicPackItemDefinition.h"
#include "Customization/FortEmotePreviewActor.h"
#include "Customization/FortItemWrapPreviewActor.h"
#include "Customization/FortPickaxePreviewActor.h"
#include "Customization/FortLoadingScreenPreviewActor.h"
#include "Customization/FortMusicPackPreviewActor.h"
#include "Customization/FortSkyDiveContrailPreviewActor.h"
#include "Customization/FortSprayPreviewActor.h"
#include "Customization/FortBodyPartOverridePreviewActor.h"
#include "Weapons/Data/FortItemWrapMappingData.h"
#include "Sound/ReverbEffect.h"
#include "Sound/SoundMix.h"
#include "Camera/CameraAnim.h"
#include "AthenaGameData.generated.h"

class AActor;
class AFortBodyPartOverridePreviewActor;
class AFortEmotePreviewActor;
class AFortItemWrapPreviewActor;
class AFortLoadingScreenPreviewActor;
class AFortMusicPackPreviewActor;
class AFortPickaxePreviewActor;
class AFortSkyDiveContrailPreviewActor;
class AFortSprayPreviewActor;
class UAthenaBattleBusItemDefinition;
class UAthenaCharacterItemDefinition;
class UAthenaDanceItemDefinition;
class UAthenaGliderItemDefinition;
class UAthenaMusicPackItemDefinition;
class UAthenaPickaxeItemDefinition;
class UAthenaSeasonItemDefinition;
class UAthenaSkyDiveContrailItemDefinition;
class UCameraAnim;
class UCurveLinearColor;
class UDataTable;
class UFortCosmeticItemMarkupTable;
class UFortItemDefinition;
class UFortItemWrapMappingData;
class UFortRespawnDataTable;
class UReverbEffect;
class USoundMix;
class UTexture2D;

UCLASS()
class FORTNITEGAME_API UAthenaGameData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAthenaGameData() 
	{
		this->FallbackSeason = NULL;
		this->DefaultBattleBusSkin = NULL;
		this->DefaultGliderSkin = NULL;
		this->DefaultContrailEffect = NULL;
		this->DefaultMusicPack = NULL;
		this->CosmeticMarkupTable = NULL;
		this->ItemWrapConfigAsset = NULL;
		this->PlaceholderItemToShowForDeniedCosmetics = NULL;
		this->TimeOfDayRGBForPeripherals = NULL;
		this->AthenaSoundMix = NULL;
		this->AthenaReverbEffect = NULL;
		this->VisualizationSoundMix = NULL;
		this->DroneCameraAnim = NULL;
		this->ThirdPersonCameraAnim = NULL;
		this->ArenaCameraAnim = NULL;
		this->RespawnDataTable = NULL;
	}
	UPROPERTY(EditAnywhere, Category = "Fallback Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TSoftObjectPtr<UAthenaPickaxeItemDefinition> FallbackPickaxe;

	UPROPERTY(EditAnywhere, Category = "Fallback Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TSoftObjectPtr<UAthenaDanceItemDefinition> FallbackDance;

	UPROPERTY(EditAnywhere, Category = "Fallback Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UAthenaSeasonItemDefinition* FallbackSeason;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TArray<TSoftObjectPtr<UFortItemDefinition>> ShuffleTileItemDefinitions;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UAthenaBattleBusItemDefinition* DefaultBattleBusSkin;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UAthenaGliderItemDefinition* DefaultGliderSkin;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UAthenaSkyDiveContrailItemDefinition* DefaultContrailEffect;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UAthenaMusicPackItemDefinition* DefaultMusicPack;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TArray<FPrimaryAssetId> ValidMaleSkinsForAnonymousMode;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TArray<FPrimaryAssetId> ValidFemaleSkinsForAnonymousMode;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TArray<FPrimaryAssetId> ValidBackPacksForAnonymousMode;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UFortCosmeticItemMarkupTable* CosmeticMarkupTable;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TSoftObjectPtr<UDataTable> CosmeticPreviewActionList;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortEmotePreviewActor> EmotePreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortItemWrapPreviewActor> ItemWrapPreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortLoadingScreenPreviewActor> LoadingScreenPreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortSprayPreviewActor> SprayPreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortMusicPackPreviewActor> MusicPackPreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortSkyDiveContrailPreviewActor> SkyDiveContrailPreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortBodyPartOverridePreviewActor> BodyPartOverridePreviewActorClass;

	UPROPERTY(EditAnywhere, Category = "Preview", meta = (IgnoreForMemberInitializationTest))
	TSoftClassPtr<AFortPickaxePreviewActor> PickaxeCosmeticPreviewActorClass;

//	UPROPERTY(EditAnywhere, Category = "Preview")
//	TMap<ECommonInputType, UTexture2D*> CosmeticPreviewActionMap;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UFortItemWrapMappingData* ItemWrapConfigAsset;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TSoftObjectPtr<UTexture2D> DeniedCosmeticThumbnail;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	UFortItemDefinition* PlaceholderItemToShowForDeniedCosmetics;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TArray<UAthenaCharacterItemDefinition*> RandomCharacters;

	UPROPERTY(EditAnywhere, Category = "Default Cosmetics", meta = (IgnoreForMemberInitializationTest))
	TArray<struct FGameplayTagMessage> UnableToPerformActionMessages;

	UPROPERTY(EditAnywhere, Category = "TOD", meta = (IgnoreForMemberInitializationTest))
	UCurveLinearColor* TimeOfDayRGBForPeripherals;

	UPROPERTY(EditAnywhere, Category = "Sound", meta = (IgnoreForMemberInitializationTest))
	USoundMix* AthenaSoundMix;

	UPROPERTY(EditAnywhere, Category = "Sound", meta = (IgnoreForMemberInitializationTest))
	UReverbEffect* AthenaReverbEffect;

	UPROPERTY(EditAnywhere, Category = "Sound", meta = (IgnoreForMemberInitializationTest))
	FName AthenaReverbEffectTag;

	UPROPERTY(EditAnywhere, Category = "Sound", meta = (IgnoreForMemberInitializationTest))
	USoundMix* VisualizationSoundMix;

	UPROPERTY(EditAnywhere, Category = "Camera", meta = (IgnoreForMemberInitializationTest))
	UCameraAnim* DroneCameraAnim;

	UPROPERTY(EditAnywhere, Category = "Camera", meta = (IgnoreForMemberInitializationTest))
	UCameraAnim* ThirdPersonCameraAnim;

	UPROPERTY(EditAnywhere, Category = "Camera", meta = (IgnoreForMemberInitializationTest))
	UCameraAnim* ArenaCameraAnim;

	//UPROPERTY(EditAnywhere, Category = "input")
	//TMap<ECommonInputType, UTexture2D*> InputTypeIcons;

	UPROPERTY(EditAnywhere, Category = "Respawn", meta = (IgnoreForMemberInitializationTest))
	UFortRespawnDataTable* RespawnDataTable;
	
};

