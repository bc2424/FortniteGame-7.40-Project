// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortniteGame.h"
#include "Components/TimelineComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "FortDecoPreview.generated.h"

class AFortDecoHelper;

UCLASS()
class AFortDecoPreview : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EBuildingAttachmentType FallbackAttachmentType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EPlacementType FallbackPlacementType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInterface> PreviewPlacementMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UCurveFloat> MotionBounceCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName CanBePlacedMaterialScalarParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ValidPlacementScalarParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InvalidPlacementScalarParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName InverseMovementVectorMaterialParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MovementEffectScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName InverseOuterScaleVectorParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName InverseInnerScaleVectorParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName WorldSpacePivotVectorParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DiffuseTextureParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FreePlacementOffset;

	UPROPERTY(EditAnywhere)
	FTimeline BounceTimeline;

	UPROPERTY(BlueprintReadOnly)
	TArray<UMaterialInstanceDynamic*> PreviewMIDs;

	UPROPERTY(BlueprintReadOnly)
	FVector DirectionChange;

	UPROPERTY(BlueprintReadOnly)
	FVector WorldSpacePivot;

	UPROPERTY(BlueprintReadOnly)
	AFortDecoHelper* ParentDecoHelper;
};

