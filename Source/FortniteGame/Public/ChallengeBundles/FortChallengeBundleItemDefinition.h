// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortAccountItemDefinition.h"
#include "Items/AthenaSeasonItemDefinition.h"
#include "FortniteGame.h"
#include "Quests/FortQuestItemDefinition.h"
#include "FortChallengeBundleScheduleDefinition.h"
#include "AthenaSeasonItemDefinition.h"
#include "FortChallengeBundleItemDefinition.generated.h"



USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortChallengeSetStyle
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	struct FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere)
	struct FLinearColor SecondaryColor;

	UPROPERTY(EditAnywhere)
	struct FLinearColor AccentColor;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UObject> DisplayImage;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UObject> CustomBackground;
};

USTRUCT()
struct FORTNITEGAME_API FFortChallengeBundleQuestEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortQuestItemDefinition> QuestDefinition;

	UPROPERTY(EditAnywhere)
	EChallengeBundleQuestUnlockType QuestUnlockType;

	UPROPERTY(EditAnywhere)
	int32 UnlockValue;

	UPROPERTY(EditAnywhere)
	FChallengeGiftBoxData RewardGiftBox;
};

USTRUCT(BlueprintType)
struct FFortChallengeBundleRewards
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int32 CompletionCount = 1;

	UPROPERTY(EditAnywhere)
	TArray<FAthenaRewardItemReference> Rewards;
};

USTRUCT(BlueprintType)
struct FFortChallengeBundleSpecialOffer
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FString Storefront;

	UPROPERTY(EditAnywhere)
	FText RichText;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterial> OfferImage;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortChallengeBundleItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FFortChallengeBundleQuestEntry> QuestInfos;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 FString CalendarEventTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 FString CalendarEventName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FFortChallengeBundleRewards> BundleCompletionRewards;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FFortChallengeBundleSpecialOffer> SpecialOffers;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 FFortChallengeSetStyle DisplayStyle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 FAthenaRewardItemReference OverrideRewardItem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UAthenaCharacterItemDefinition* CharacterOverrideForRewardPreviews;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxChainDepth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UMaterial> BundleHidenImageMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 FText UniqueLockedMessage;
};
