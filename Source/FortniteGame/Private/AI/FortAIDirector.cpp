// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.


#include "FortAIDirector.h"

// Sets default values
AFortAIDirector::AFortAIDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFortAIDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFortAIDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFortAIDirector::OnPlayerSpawn(class AFortPlayerPawn* PlayerPawn)
{

}

void AFortAIDirector::Activate()
{

}