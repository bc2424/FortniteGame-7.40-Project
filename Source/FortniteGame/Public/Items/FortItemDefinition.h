// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once
/* FortItemDefinition */
/* * Base Definition class for items in Fortnite */
#include "Styling/SlateBrush.h"
#include "CoreMinimal.h"
#include "McpProfileSys/Public/McpItemDefinitionBase.h"
#include "Items/FortItem.h"
#include "Engine/Texture2D.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "UI/FortTooltipDisplayStatsList.h"
#include "FortniteGame.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMesh.h"
#include "Engine/CurveTable.h"
#include "FortItemSeriesDefinition.h"
#include "FortItemDefinition.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortOnItemDefinitionCountChangedDelegate, UFortItemDefinition*, Definition, int32, Delta);

UCLASS(Abstract, Blueprintable)
class FORTNITEGAME_API UFortItemDefinition : public UMcpItemDefinitionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortOnItemDefinitionCountChangedDelegate OnItemCountChanged;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
	EFortRarity Rarity = EFortRarity::Uncommon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category = "Display")
		FText DisplayName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		FText ShortDescription;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		FText Description;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		FText DisplayNamePrefix;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		FText SearchTags;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display|Owned Tags")
		FGameplayTagContainer GameplayTags;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		FGameplayTagContainer SecondaryCategoryOverrideTags;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		FGameplayTagContainer TertiaryCategoryOverrideTags;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, AssetRegistrySearchable, Category = "Basic Item Info")
		EFortItemType ItemType;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Basic Item Info")
		EFortItemType PrimaryAssetIdItemTypeOverride;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Basic Item Info")
		TEnumAsByte<EFortQuality> Quality;         

	// Number of stars that an item has on its item card
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		TEnumAsByte<EFortItemTier> Tier;            

	// "Maximum" number of stars that are shown on an item's card (only shown in save the world)
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		TEnumAsByte<EFortItemTier> MaxTier;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		EFortTemplateAccess	Access;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Basic Item Info")
		bool bIsAccountItem;

	// Determines which stats are displayed when viewing a weapon in the inventory
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Tooltips")
		UFortTooltipDisplayStatsList* StatList;

	// Determines what power level an item is
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Rating")
		FCurveTableRowHandle RatingLookup;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, AssetRegistrySearchable, Category = "Release Version")
		bool bNeverPersisted = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		bool bAllowMultipleStacks = true;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		bool bAutoBalanceStacks = true;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		bool bForceAutoPickup = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Inventory Limit")
		bool bInventorySizeLimited = true;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Basic Item Info")
		bool bCalculateRarityFromQualityAndTier = false;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		FText ItemTypeNameOverride;                                  
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		EFortInventoryFilter FilterOverride;

	// Determines the maximum amount of a specific item that you can carry in a single inventory slot
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Functionality")
		int32 MaxStackSize = 1;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		TSoftObjectPtr<UTexture2D> LargePreviewImage;

	// Used by multi-slot items (items that take up more than 1 inventory slot) in Chapter 2 and onwards.
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		TSoftObjectPtr<UTexture2D> WidePreviewImage;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Display")
		FSoftObjectPath DisplayAssetPath;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		float FrontendPreviewScale = 1.0f;

	// Allows an item to have a specific "series" (kind of like a custom rarity)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Display")
		UFortItemSeriesDefinition* Series;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		FVector FrontendPreviewPivotOffset;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		FRotator FrontendPreviewInitialRotation;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		FTransform FrontendPreviewMeshOffset;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		FTransform AthenaFrontendPreviewMeshOffset;
	
	// Overrides the Frontend Preview mesh with a SkeletalMesh, an example of this being used is with the shuffle item definitions in Athena (CID_Random) where it shows a shuffle icon mesh.
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		TSoftObjectPtr<UStaticMesh> FrontendPreviewMeshOverride;
	
	// Overrides the Frontend Preview mesh with a SkeletalMesh
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Frontend Preview")
		TSoftObjectPtr<USkeletalMesh> FrontendPreviewSkeletalMeshOverride;

	  
public:
    UFortItemDefinition();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowPreviewOnCurrentHero() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStackable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInventorySizeLimited() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UFortTooltip> GetTooltip(bool bSummaryTooltip) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlateBrush GetSmallPreviewImageBrush() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetSmallPreviewImage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetSingleLineDescription() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetShortDescription() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetRichDescription() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFortColorPalette GetRarityOrSeriesColors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFortRarity GetRarity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPreviewStaticMeshAsset(TSoftObjectPtr<UStaticMesh>& Asset) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPreviewSkeletalMeshAsset(TSoftObjectPtr<USkeletalMesh>& Asset) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPreviewPrefabAsset(TSoftClassPtr<AActor>& Asset) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetPreviewMeshOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPreviewAssets(TArray<TSoftObjectPtr<UObject>>& Assets) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPersistentName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetLargePreviewImage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetItemTypeName(bool bUsePlural) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFortItemType GetItemType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFortTooltipDisplayStatsList* GetDisplayStats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetDisplayName(bool bBaseName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSoftObjectPath GetDisplayAssetPath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FText> GetDescription() const;
    
    UFUNCTION(BlueprintCallable)
    void CustomizePreviewPrefab(AActor* PrefabInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void CustomizePreviewMesh(UMeshComponent* Mesh) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFortItem* CreateTemporaryItemInstanceBP(int32 Count, int32 Level) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFortItem* CreateTemporaryInstanceFromExistingItemBP(UFortItem* ExistingItem, int32 Count, int32 Level) const;
	
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const PURE_VIRTUAL(GetOwnedGameplayTags,);
    
};
