// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "GameplayTags.h"
#include "FortniteGame/FortniteGame.h"
#include "Items/FortWorldItemDefinition.h"
#include "Items/FortItemDefinition.h"
#include "Items/FortGiftBoxItemDefinition.h"
#include "AthenaSeasonItemDefinition.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGiftBoxFortmatData 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FString StringAssetType; 

	UPROPERTY(EditAnywhere)
	FString StringData;
};

USTRUCT()
struct FAthenaSeasonBannerLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> SurroundImage;                                   

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UMaterialInterface> BannerMaterial; 

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FChallengeGiftBoxData 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	 TSoftObjectPtr<UFortGiftBoxItemDefinition> GiftBoxToUse; 

	UPROPERTY(EditAnywhere)
	 TArray<FFortGiftBoxFortmatData> GiftBoxFormatData;
};
USTRUCT(BlueprintType)
struct FORTNITEGAME_API FAthenaRewardItemReference 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere)
	FString TemplateId;

	UPROPERTY(EditAnywhere)
	int Quantity = 1; 

	UPROPERTY(EditAnywhere)
	FChallengeGiftBoxData RewardGiftBox; 

	UPROPERTY(EditAnywhere)
	bool IsChaseReward;

	UPROPERTY(EditAnywhere)
	EAthenaRewardItemType RewardType; 

	UPROPERTY(EditAnywhere)
	EAthenaRewardVisualImportanceType RewardVisualImportanceType; 
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FAthenaRewardScheduleLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FAthenaRewardItemReference> Rewards;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FAthenaRewardSchedule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FAthenaRewardScheduleLevel> Levels;
};

USTRUCT()
struct FORTNITEGAME_API FAthenaSeasonBannerLevelSchedule
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<FAthenaSeasonBannerLevel> Levels; 
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaSeasonItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UAthenaSeasonItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Season Config")
		int SeasonNumber;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		int NumSeasonLevels;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		int NumBookLevels;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		EAthenaSeasonShopVisibility SeasonShopVisibility;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		EAthenaChallengeTabVisibility ChallengesVisibility;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		UDataTable* SeasonXpCurve;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		UDataTable* BookXpCurve;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		FString SeasonStorefront;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		FString BattlePassLevelOfferID;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		FPrimaryAssetId FreeTokenItemPrimaryAssetId;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		TArray<int32> FreeLevelsThatNavigateToBattlePass;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		TArray<int32> FreeLevelsThatAutoOpenTheAboutScreen;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		 FAthenaRewardSchedule SeasonXpScheduleFree;

	UPROPERTY(EditAnywhere, Category = "Season Config")
	     FGameplayTag FreeSeasonItemContentTag;
	
    UPROPERTY(EditAnywhere, Category = "Season Config")
	    FAthenaRewardSchedule BookXpScheduleFree;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		FGameplayTag BattlePassFreeItemContentTag;
	
    UPROPERTY(EditAnywhere, Category = "Season Config")
	    FAthenaRewardSchedule BookXpSchedulePaid;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		FGameplayTag BattlePassPaidItemContentTag;
	
    UPROPERTY(EditAnywhere, Category = "Season Config")
	FAthenaSeasonBannerLevelSchedule SeasonBannerSchedule;
	
    UPROPERTY(EditAnywhere, Category = "Season Config")
       class UFortChallengeBundleItemDefinition* SeasonalGlyphChallengeBundle;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
		FString GlyphTokenTemplateId;

	UPROPERTY(EditAnywhere, Category = "Season Config")
	    UDataTable* SeasonalGlyphRewards;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
	    class UFortChallengeBundleScheduleDefinition* ChallengeSchedulePaid;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
	    TArray<UFortChallengeBundleScheduleDefinition*> ChallengeSchedulesAlwaysShown;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
	    FAthenaRewardScheduleLevel SeasonGrantsToEveryone;
	 
	UPROPERTY(EditAnywhere, Category = "Season Config")
		FGameplayTag SeasonGrantsToEveryoneItemContentTag;
	
    UPROPERTY(EditAnywhere, Category = "Season Config")
	    FAthenaRewardScheduleLevel SeasonFirstWinRewards;

	UPROPERTY(EditAnywhere, Category = "Season Config")
		FGameplayTag SeasonFirstWinItemContentTag;
	
	UPROPERTY(EditAnywhere, Category = "Season Config")
	FAthenaRewardScheduleLevel BattleStarSubstitutionReward;
	
	UPROPERTY(EditAnywhere, Category = "End of Season")
		TArray<TSoftObjectPtr< UFortItemDefinition>> ExpiringRewardTypes;

	UPROPERTY(EditAnywhere, Category = "End of Season")
		TArray<TSoftObjectPtr<UFortItemDefinition>> TokensToRemoveAtSeasonEnd;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaSeason", GetFName());
	}
};