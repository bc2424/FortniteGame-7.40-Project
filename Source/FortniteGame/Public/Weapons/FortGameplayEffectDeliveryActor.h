// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "AI/FortAIController.h"
#include "Abilities/FortGameplayAbility_Structs.h"
#include "FortGameplayEffectDeliveryActor.generated.h"

USTRUCT(BlueprintType)
struct FFortSpawnContext
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<EFortTeam::Type> Team;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API AFortGameplayEffectDeliveryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFortGameplayEffectDeliveryActor();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnTouch;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bKillOnExplode;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bSetHiddenOnKill;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bKillOnMaxTargetsTouched;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIgnoreInstigatorCollision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FFortGameplayEffectContainerSpec> AdditionalExplodeEffectContainers;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LifespanAfterKill;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TouchingActorsEffectApplicationUpdateTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsBeingKilled;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bHasExploded;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAddHitResultToTouchApplication;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExplosionTransformIgnoresRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCanExplodeMultipleTimes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UPrimitiveComponent* CollisionComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bDoExplosionReentrancyGuard;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
