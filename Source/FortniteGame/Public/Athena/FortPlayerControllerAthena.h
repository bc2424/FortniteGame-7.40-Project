// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Components/SlateWrapperTypes.h"
#include "Player/FortPlayerControllerGameplay.h"
#include "FortPlayerControllerAthena.generated.h"


USTRUCT(BlueprintType)
struct FSettingsHUDVisibilityAndText
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag HUDVisibilityGameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ESlateVisibility DefaultHUDVisibility;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText ToolTipText;
};


/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerControllerAthena : public AFortPlayerControllerGameplay
{
	GENERATED_BODY()

		
		UFUNCTION(BlueprintCallable)
			void ServerThankBusDriver();
		
		UFUNCTION(BlueprintCallable)
		void ServerStartMinigame();
		
		UFUNCTION(BlueprintCallable)
		void ServerSpawnCreativeSupplyDrop(struct FVector Position, class UClass* InSupplyDropClass);
		
		UFUNCTION(BlueprintCallable)
		void ServerRestartMinigame();
		
		UFUNCTION(BlueprintCallable)
		void ServerEndMinigame(bool bAbandon);
		
		UFUNCTION(BlueprintCallable)
		void ServerEndLoadingVolume(class AActor* VolumeToLoad);
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FSettingsHUDVisibilityAndText>       HUDVisibilityGameplayTags;
};
