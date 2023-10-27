// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortAIDirector.generated.h"

UCLASS()
class FORTNITEGAME_API AFortAIDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFortAIDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Blueprintable, BlueprintCallable)
		void Activate();

	UFUNCTION(Blueprintable, BlueprintCallable)
		void OnPlayerSpawn(class AFortPlayerPawn* PlayerPawn);

};
