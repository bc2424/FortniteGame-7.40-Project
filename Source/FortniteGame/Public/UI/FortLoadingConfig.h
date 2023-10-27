// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateTypes.h"
#include "FortTips.h"
#include "FortLoadingConfig.generated.h"

USTRUCT()
struct FFortLoadingBlockScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	 FProgressBarStyle LoadingProgressBar;

	UPROPERTY(EditAnywhere)
	 FMargin LoadingProgressBarPadding;

	UPROPERTY(EditAnywhere)
	 FTextBlockStyle LoadingTextStyle;

	UPROPERTY(EditAnywhere)
	 FMargin LoadingTextPadding;
};

USTRUCT()
struct FFortLogoLoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FLinearColor LogoColor;

	UPROPERTY(EditAnywhere)
	 FMargin LogoPadding;

	UPROPERTY(EditAnywhere)
	float LogoSize;
};

USTRUCT()
struct FFortSubGameLoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<UFortTips*> Tips;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UObject> BackgroundImage;

	UPROPERTY(EditAnywhere)
	 FVector2D BackgroundDesiredSize;

	UPROPERTY(EditAnywhere)
	 FLinearColor BackgroundColor;

	UPROPERTY(EditAnywhere)
	 FFortLogoLoadingScreen LogoLoadingScreen;

	UPROPERTY(EditAnywhere)
	 FFortLoadingBlockScreen LoadingBlockScreen;
};

USTRUCT()
struct FFortEarlyAcessLoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	 FSlateBrush EABackground;

	UPROPERTY(EditAnywhere)
	 FTextBlockStyle EATextStyle;
};

USTRUCT()
struct FFortPSALoadingScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int32 PercentChance;

	UPROPERTY(EditAnywhere)
	int32 MinimumGames;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UUserWidget> WidgetClass;
};

UCLASS(Blueprinttype)
class FORTNITEGAME_API UFortLoadingConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FFortSubGameLoadingScreen LoadingScreenFallback;

	UPROPERTY(EditAnywhere)
	FFortSubGameLoadingScreen LoadingScreens[0x2];

	UPROPERTY(EditAnywhere)
	FFortEarlyAcessLoadingScreen LoadingScreenEA;

	UPROPERTY(EditAnywhere)
	FSlateBrush LoadingScreenMissionBackground;

	UPROPERTY(EditAnywhere)
	FSlateBrush LoadingScreenTipBackground;

	UPROPERTY(EditAnywhere)
	TArray<FFortPSALoadingScreen> PSALoadingScreens;
};
