// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemDefinition.h"
#include "FortWeapon.h"
#include "GameFramework/Actor.h"
#include "FortDecoTool.generated.h"


UCLASS()
class AFortDecoTool : public AFortWeapon
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool bButtonDown;

    UPROPERTY(EditAnywhere)
	class UFortItemDefinition* ItemDefinition;

    UPROPERTY(EditAnywhere)
    class AFortDecoHelper* DecoHelper;

    UPROPERTY(EditAnywhere)
     AActor* CarriedActor;

    UPROPERTY(EditAnywhere)
    bool bPlaceCarriedActor;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UParticleSystem> SpawnEffect;

    UPROPERTY(EditAnywhere)
    bool bPreventExecutionOnOwningPlayerFalling;
};







