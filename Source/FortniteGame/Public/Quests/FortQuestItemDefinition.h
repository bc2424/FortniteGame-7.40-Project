// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortAccountItemDefinition.h"
#include "FortniteGame.h"
#include "FortScriptedAction.h"
#include "Conversation/FortConversation.h"
#include "FortItemQuantityPair.h"
#include "FortHiddenRewardQuantityPair.h"
#include "FortMcpQuestRewardInfo.h"
#include "FortMcpQuestObjectiveInfo.h"
#include "FortQuestMissionCreationContext.h"
#include "FortMissionConfigDataParams.h"
#include "FortQuestItemDefinition.generated.h"

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortQuestItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable)
	EFortQuestType QuestType;
	
	UPROPERTY(EditAnywhere)
	bool bShouldDisplayOverallQuestInformation;

	UPROPERTY(EditAnywhere)
	bool bAthenaUpdateObjectiveOncePerMatch;

	UPROPERTY(EditAnywhere)
	bool bAthenaMustCompleteInSingleMatch;

	UPROPERTY(EditAnywhere)
	bool bUpdateObjectiveOncePerMatch;

	UPROPERTY(EditAnywhere)
	bool IsStreamingRequired;

	UPROPERTY(EditAnywhere)
	bool bExpandsStormShield;

	UPROPERTY(EditAnywhere)
	bool bHidden;

	UPROPERTY(EditAnywhere)
	bool bIncludedInCategories = true;

	UPROPERTY(EditAnywhere)
	bool bAutoLaunch;

	UPROPERTY(EditAnywhere)
	bool bDeprecated;

	UPROPERTY(EditAnywhere)
	bool bDisableBackendConditionEvaluation;

	UPROPERTY(EditAnywhere)
	bool bAllowTileMatching = true;

	UPROPERTY(EditAnywhere)
	bool bAllowPlayNowNavigation = true;

	UPROPERTY(EditAnywhere)
	bool bAllowMissionAlertMatchesBypassingTileRequirements;

	UPROPERTY(EditAnywhere)
	bool bTutorialQuest;

	UPROPERTY(EditAnywhere)
	int32 ExpirationDuration;

	UPROPERTY(EditAnywhere)
	int32 ObjectiveCompletionCount = -1;

	UPROPERTY(EditAnywhere, Category = "Quest Rewards")
	TArray<FFortItemQuantityPair> Rewards;

	UPROPERTY(EditAnywhere, Category = "Quest Rewards")
	UDataTable* RewardsTable;
	
	UPROPERTY(EditAnywhere, Category = "Quest Rewards")
	TArray<FFortHiddenRewardQuantityPair> HiddenRewards;

	UPROPERTY(EditAnywhere, Category = "Quest Rewards")
	TArray<FString> FeatureRewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest Rewards")
	TArray<FFortMcpQuestRewardInfo> SelectableRewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FFortMcpQuestObjectiveInfo> Objectives;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTagContainer Prerequisites;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortQuestItemDefinition> PrerequisiteQuest;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle PrerequisiteObjective;

	UPROPERTY(EditAnywhere, Category = "Quest Pack")
	float Weight = 1.0f;

	UPROPERTY(EditAnywhere)
	uint16 GranterWindowPeriodMinutes;

	UPROPERTY(EditAnywhere)
	uint16 GranterCooldownPeriodSeconds;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle Category;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortConversation> IntroConversation;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortConversation> SelectRewardsConversation;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortConversation> ClaimConversation;

	UPROPERTY(EditAnywhere)
	FText RewardHeaderText;

	UPROPERTY(EditAnywhere)
	FText RewardDescription;

	UPROPERTY(EditAnywhere, Category = "Display")
	FText CompletionText;

	UPROPERTY(EditAnywhere, Category = "Mission")
	TArray<FFortQuestMissionCreationContext> MissionCreationContexts;

	UPROPERTY(EditAnywhere, Category = "Mission")
	FFortMissionConfigDataParams MissionConfigMetadata;

	UPROPERTY(EditAnywhere, Category = "Display")
	uint32 ClaimPriority = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SortPriority;

};