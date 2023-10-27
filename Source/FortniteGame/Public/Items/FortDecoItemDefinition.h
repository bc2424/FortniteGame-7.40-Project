// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponItemDefinition.h"
#include "Building/BuildingActor.h"
#include "EditMode/BuildingEditModeMetadata.h"
#include "FortDecoPreview.h"
#include "FortDecoItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UFortDecoItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()
public:
	UFortDecoItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Building Actor")
	TSoftClassPtr<ABuildingActor> BlueprintClass;

	UPROPERTY(EditAnywhere, Category = "Building Actor")
	TSoftClassPtr<AFortDecoPreview> PlacementPreviewClass;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	float GridSnapSizeOverride = -1.0f;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	float RotationAngleIncrement = 90.0f;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	float GridPlacementOffset;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	EPlacementType PlacementTypeOverride= EPlacementType::None;  
		
	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bForceIgnoreOverlapTest = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bIgnoreCollisionWithVehicles  = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bForceIgnoreBuildingOverlaps;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bIgnoreCollisionWithCriticalActors;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bIgnoreCollisionWithStructuralGridActors  = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bIgnoreCollisionWithFortStaticMeshActors  = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bIgnoreCollisionWithPlayers = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bDisableLocationLerpWhilePlacing = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bDisableRotationLerpWhilePlacing = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bDisableScaleLerpWhilePlacing = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bAttachWhenPlacing = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bAllowPlacementOnWorldGeometry;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bAllowPlacementOnBuildings = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bDestroySmallObjectsWhenPlaced;

	UPROPERTY(EditAnywhere, Category = "Functionality")
	bool bConsumeWhenPlaced  = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bCancelToolWhenPlaced;

	UPROPERTY(EditAnywhere, Category = "Functionality")
	bool bCancelAbilityOnUnequip;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	bool bRequiresPlayerPlaceableAttachmentActors;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bUseRelativeCameraRotation = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bAllowStairsWhenAttachingToFloors;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bSnapYawToHorizontalAxes;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bAllowAnyFloorPlacement;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bRequiresPermissionToEditWorld = true;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	bool bAutoCreateAttachmentBuilding;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	int32 MaxPlacementDistance = 512;

	UPROPERTY(EditAnywhere, Category = "Placement Info")
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AutoCreateAttachmentBuildingShapes;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AllowedShapes;

	UPROPERTY(EditAnywhere, Category = "Attachment")
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AllowedPlayerBuiltShapes;
};