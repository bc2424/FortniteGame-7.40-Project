// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortniteGame.h"
#include "Components/TimelineComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Building/BuildingActor.h"
#include "Building/BuildingSMActor.h"
#include "FortDecoPreview.h"
#include "FortDecoItemDefinition.h"
#include "FortDecoTool.h"
#include "FortDecoHelper.generated.h"

class AFortDecoTool;
class AFortDecoPreview;
class UFortDecoItemDefinition;

USTRUCT(BlueprintType)
struct FDecoPlacementState
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FVector Start;

    UPROPERTY(EditAnywhere)
    FVector End;

    UPROPERTY(EditAnywhere)
    FVector RawLocation;

    UPROPERTY(EditAnywhere)
    FVector Normal;

    UPROPERTY(EditAnywhere)
    FQuat AbsoluteRotation;

    UPROPERTY(EditAnywhere)
    FVector GridLocation;

    UPROPERTY(EditAnywhere)
    FVector PreviousLocation;

    UPROPERTY(EditAnywhere)
    FVector FallbackLocation;

    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<AActor> LastHitActor;

    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<ABuildingSMActor> CurrentBuildingActorAttachment;

    UPROPERTY(EditAnywhere)
    FVector CreateBuildingLocation;

    UPROPERTY(EditAnywhere)
    FRotator CreateBuildingRotation;

    UPROPERTY(EditAnywhere)
    EFortDecoPlacementQueryResults CanPlaceState;
};

UCLASS()
class AFortDecoHelper : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    AFortDecoPreview* DecoPreview;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<ABuildingActor> PlacementActorClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TWeakObjectPtr<AFortDecoTool> DecoTool;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DecoToolReach;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EBuildingAttachmentType CurrentAttachmentType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPlacementType CurrentPlacementType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFortDecoItemDefinition* DecoItemDefinition;

    UPROPERTY(EditAnywhere)
    FVector LocationData[2];

    UPROPERTY(EditAnywhere)
    FRotator RelativeRotationData[2];

    UPROPERTY(EditAnywhere)
    FRotator AbsoluteRotationData[2];

    UPROPERTY(EditAnywhere)
    float ScaleData[2];

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FDecoPlacementState PlacementInfo;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bInFallbackPosition;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float FallbackTinyScale;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EFortDecoPlacementQueryResults CanPlaceState;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText CustomPlacementText;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DesiredRelativeRotation;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector DirectionChange;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float GridSnapSize;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FRotator FreeFloorPlacementRelativeRotationOffset;
};

