// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AthenaSeasonItemDefinition.h"
#include "UserWidget.h"
#include "FortniteGame.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortChallengeBundleScheduleDefinition.generated.h"


USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortChallengeBundleScheduleEntry
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> ChallengeBundle;

	UPROPERTY(EditAnywhere)
	 EChallengeScheduleUnlockType UnlockType = EChallengeScheduleUnlockType::OnScheduleGranted;                                        

	UPROPERTY(EditAnywhere)
	int32 UnlockValue;    
};


UCLASS(BlueprintType)
class FORTNITEGAME_API UFortChallengeBundleScheduleDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	TArray<FFortChallengeBundleScheduleEntry> ScheduleEntries;                                 

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FString CalendarEventTag;

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FString CalendarEventName;

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FGameplayTag RequiredMcpContextTags;

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule|Advanced")
	FChallengeGiftBoxData GrantedBundleGiftBox;

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	bool  CleanUpOnBundleCompletion;

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FGameplayTag CategoryTag;
	
	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FGameplayTag ChallengeDetailsTag;

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FGameplayTag SourceTag;

	UPROPERTY(EditAnywhere, Category = "Display")
	bool bSeperateEachBundleForDisplay;

	UPROPERTY(EditAnywhere, Category = "Display")
	bool bSeperateEachBundleForTracking;                  

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	int32 SortPriority;                                     

	UPROPERTY(EditAnywhere, Category = "Challenge Bundle Schedule")
	FText UnlockTextOverride;
	
	UPROPERTY(EditAnywhere, Category = "Display")
	TArray<TSoftClassPtr<UUserWidget>> CustomChallengeHeaderExtensions;
};
	

