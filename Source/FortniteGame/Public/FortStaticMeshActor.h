// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/ObjectMacros.h"
#include "Components/ActorComponent.h"
#include "AI/Navigation/NavRelevantInterface.h"
#include "NavRelevantComponent.h"
#include "FortStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class AFortStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, Transient)
	TArray<UNavRelevantComponent*> LinkComps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseAutoNavmeshFlags;
	
};