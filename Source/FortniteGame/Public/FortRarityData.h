// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Engine/DataAsset.h"
#include "FortRarityData.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortRarityItemData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText Name;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor Color1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor Color2;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor Color3;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor Color4;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor Color5;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Radius;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Falloff;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Brightness;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Roughness;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Glow;
};

UCLASS()
class FORTNITEGAME_API UFortRarityData : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
		FFortRarityItemData RarityCollection[8];

	UFortRarityData();
	UFUNCTION(BlueprintCallable)
    static FFortRarityItemData BPGetRarityData(EFortRarity Rarity);
    
	UFUNCTION(BlueprintCallable)
	static FFortColorPalette BPGetRarityColorPalette(EFortRarity Rarity);
    
};
