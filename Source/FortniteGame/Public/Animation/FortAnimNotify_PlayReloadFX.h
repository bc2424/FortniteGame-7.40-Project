// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "FortniteGame.h"
#include "FortAnimNotify_PlayReloadFX.generated.h"

/**
 * 
 */

UCLASS()
class FORTNITEGAME_API UFortAnimNotify_PlayReloadFX : public UAnimNotify
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
		EFortReloadFXState ReloadStage;

};
