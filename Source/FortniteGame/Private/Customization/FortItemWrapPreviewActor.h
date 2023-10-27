// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/AthenaItemWrapDefinition.h"
#include "FortItemWrapPreviewActor.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FItemWrapPreviewEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UObject> PreviewObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransform PreviewTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int WrapSectionLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPreviewUsingVehicleShader;
};

UCLASS()
class FORTNITEGAME_API AFortItemWrapPreviewActor : public AActor
{
	GENERATED_BODY()
public:

	UPROPERTY(Transient)
	FItemWrapPreviewEntry CurrentEntryInfo;
	
protected:
	UPROPERTY(BlueprintReadOnly)
	UAthenaItemWrapDefinition* MyWrap;
};