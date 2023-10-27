// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaBattleBusItemDefinition.generated.h"

/**
 * 
 */

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaBattleBusItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UAthenaBattleBusItemDefinition();
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> IgnitionSound;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> LobbyLoopingMusic;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> LobbyLoopingSound;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> FlightLoopingMusic;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> FlightLoopingSound;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
    USoundBase* GetLobbyLoopingSound() const;
        
	UFUNCTION(BlueprintCallable, BlueprintPure)
	USoundBase* GetLobbyLoopingMusic() const;
        
	UFUNCTION(BlueprintCallable, BlueprintPure)
	USoundBase* GetIgnitionSound() const;
        
	UFUNCTION(BlueprintCallable, BlueprintPure)
	USoundBase* GetFlightLoopingSound() const;
        
	UFUNCTION(BlueprintCallable, BlueprintPure)
	USoundBase* GetFlightLoopingMusic() const;
        
	UFUNCTION(BlueprintCallable, BlueprintPure)
	TSoftClassPtr<ABattleBusCosmeticInstanceBase> GetBusPrefabClass() const;
        
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaBattleBus", GetFName());
	}
};