// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaMusicPackItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaMusicPackItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaMusicPackItemDefinition();
	UPROPERTY(EditAnywhere, meta = (AssetBundles = "Equipped"), Category = "Audio")
		TSoftObjectPtr<USoundBase> FrontEndLobbyMusic;

	UPROPERTY(EditAnywhere, Category = "Display")
		TSoftObjectPtr<UTexture2D> CoverArtImage;

	UPROPERTY(EditAnywhere, Category = "Audio")
		bool bIsDefaultMusicPack;

	UPROPERTY(EditAnywhere, Category = "Audio")
		float MusicPreviewStartTime;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaMusicPack", GetFName());
	}
};
