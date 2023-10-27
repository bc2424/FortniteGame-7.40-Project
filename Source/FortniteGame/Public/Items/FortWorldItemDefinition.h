// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Items/FortItemDefinition.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "Engine/StaticMesh.h"
#include "Engine/SkeletalMesh.h"
#include "Sound/SoundBase.h"
#include "FortniteGame.h"
#include "FortWorldItemDefinition.generated.h"


USTRUCT()
struct FFortPickupTagTestContainer
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere)
		FText FailReason;
};

USTRUCT(BlueprintType)
struct FFortPickupRestrictionLists
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
		FFortPickupTagTestContainer WhiteList;

	UPROPERTY(EditAnywhere)
		FFortPickupTagTestContainer Blacklist;
};



UCLASS()
class FORTNITEGAME_API UFortWorldItemDefinition : public UFortItemDefinition
{
	GENERATED_BODY()

public:
	UFortWorldItemDefinition()
	{
		bInventorySizeLimited = true;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Tags|Gameplay")
		FGameplayTagContainer RequiredEquipTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Tags|Gameplay")
		FGameplayTagContainer OverrideAutoEquipTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Stats")
		EFortReplicatedStat AccumulatingStatType;

	// doesn't exist in 9.10
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite) 
	//	TArray<FFortPickupRestrictionLists> PickupRestrictionListEntry; 

	// Determines what an item does once dropped by a player.
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		EWorldItemDropBehavior DropBehavior;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bIgnoreRespawningForDroppingAsPickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bCanAutoEquipByClass = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bPersistInInventoryWhenFinalStackEmpty = false;

	// Used to determine if you can select an item in the quickbar.
	// Leave true if you want to equip the item traditionally.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bSupportsQuickbarFocus = true;

	// Used to determine if you can select an item in the quickbar, specifically for controller. 
	// Leave true if you want to equip the item traditionally on controller.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bSupportsQuickbarFocusForGamepadOnly = true;

	// Related to when the item is selected in the quickbar, unsure what it's used for.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bShouldActivateWhenFocused = true;

	// Forces the item to be focused when added to the quickbar.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bForceFocusWhenAdded = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bForceIntoOverflow = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bForceStayInOverflow = true;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bDropCurrentItemOnOverflow = true;
		
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bHasDisintegrationValue = true; 

	// Should this item show description? true = yes, false = no.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bShouldShowItemToast = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bShowDirectionalArrowWhenFarOff = true;

	// Determines if an item can be dropped, or if it is locked to your inventory.
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bCanBeDropped = true;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info")
		bool bCanBeReplacedByPickup = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bItemCanBeStolen = true;

	// Determines if an item can be put into Storm Shield Storage.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bCanBeDepositedInStorageVault = true;

	// Determines if an item has durability, true by default.
	UPROPERTY(EditAnywhere, Category = "World Item Info|Durability")
		bool bItemHasDurability = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bAllowedToBeLockedInInventory = true;

	//Overrides the dimensions of the Pickup Mesh
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info")
		bool bOverridePickupMeshTransform = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bDisplayPlayerNameForInventoryActor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bDisplayHealthForInventoryActor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bDisplayShieldForInventoryActor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		bool bAlwaysCountForCollectionQuest = true;

	// Should item drop when holder dies?
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bDropOnDeath = true;

	// Should item drop when holder logs out?
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bDropOnLogout = true;

	// Should item drop when holder gets knocked?
	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		bool bDropOnDBNO = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Schematics")
		bool bDoesNotNeedSourceSchematic = true;

	//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
	//		bool bUsesGoverningTags; //doesn't exist in 9.10

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info")
		int DropCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		float MiniMapViewableDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info")
		FText OwnerPickupText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info")
		FDataTableCategoryHandle LootLevelData;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info")
		FTransform PickupMeshTransform;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Special Actor Item|Tags")
		FGameplayTag SpecialActorBaseTag;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Special Actor Item|Tags")
		FGameplayTag SpecialActorPickupTag;

	//	UPROPERTY(EditAnywhere, Category = "World Item Info|Special Actor Item|Stats Lists")
	//		TArray<FSpecialActorSingleStatData> SpecialActorPickupStatList;

	//	UPROPERTY(EditAnywhere, Category = "World Item Info|Special Actor Item|Stats Lists")
	//		TArray<FSpecialActorSingleStatData> SpecialActorInventoryStatList;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Special Actor Item")
		FName PickupSpecialActorUniqueID;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Special Actor Item|Tags")
		FGameplayTag SpecialActorInventoryTag;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info|Despawning")
		FScalableFloat PickupDespawnTime;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info|Despawning")
		FScalableFloat InStormPickupDespawnTime;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info|Culling")
		FScalableFloat NetworkCullDistanceOverride; // idk what this would do

	UPROPERTY(EditAnywhere, Category = "World Item Info|Minimap")
		FSlateBrush PickupMinimapIconBrush;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Minimap")
		FVector2D PickupMinimapIconScale;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Compass")
		FSlateBrush PickupCompassIconBrush;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Compass")
		FVector2D PickupCompassIconScale;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Minimap")
		FSlateBrush InventoryMinimapIconBrush;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Minimap")
		FVector2D InventoryMinimapIconScale;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Compass")
		FSlateBrush InventoryCompassIconBrush;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Compass")
		FVector2D InventoryCompassIconScale;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Slots")
		uint8 NumberOfSlotsToTake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Item Pickup Info")
		TSoftObjectPtr<UStaticMesh> PickupStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Item Pickup Info")
		TSoftObjectPtr<USkeletalMesh> PickupSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Item Info|Item Pickup Info")
		TSoftClassPtr<AActor> PickupEffectOverride;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info|Sounds")
		TSoftObjectPtr<USoundBase> PickupSound;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Pickup Info|Sounds")
		TSoftObjectPtr<USoundBase> PickupByNearbyPawnSound;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info|Sounds")
		TSoftObjectPtr<USoundBase> DropSound;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Item Drop Info|Sounds")
		TSoftObjectPtr<USoundBase> DroppedLoopSound;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Durability")
		FDataTableRowHandle DisassembleRecipe;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Durability")
		float DisassembleDurabilityDegradeMinLootPercent; 

	UPROPERTY(EditAnywhere, Category = "World Item Info|Durability")
		float DisassembleDurabilityDegradeMaxLootPercent;

	UPROPERTY(EditAnywhere, Category = "World Item Info")
		int32 FabricationValueOverride;

	UPROPERTY(EditAnywhere, Category = "World Item Info|Slots")
		int32 PreferredQuickbarSlot;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Level")
	   int32 MinLevel;                                       

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Level")
	   int32 MaxLevel;
};
