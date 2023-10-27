#pragma once
#include "CoreMinimal.h"
#include "FortEventName.h"
#include "FortMissionInfo.h"
#include "Engine/DataTable.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortDifficultyOptionCategoryEncounter.h"
#include "FortniteGame.h"
#include "FortMission_Structs.generated.h"

class UFortMissionInfo;
class AActor;
class UDataAsset;
class UFortMissionEventParams;
class UObject;
class UFortDifficultyOptionCategoryEncounter;
class UFortDifficultyOptionEncounter;

class UFortMissionInfoIndicator;
class UFortBadgeItemDefinition;
class UFortMissionInfo;
class UFortMissionEventDelegateHolder;
class UFortQuestItemDefinition;

USTRUCT(BlueprintType)
struct FFortMissionEventReceiverByGameplayTagQuery {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery TagQueryEventDiscriminator;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortMissionEventDelegateHolder* DelegateHolder;
};


class UFortMissionInfo;

USTRUCT(BlueprintType)
struct FFortGlobalMission {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<EFortTheaterType> AllowedTheaterTypes;
    
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery TheaterTagQuery;
    
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery RegionTagQuery;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<EFortZoneType> AllowedZoneTypes;
    
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery ZoneTagQuery;
    
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery PrimaryMissionTagQuery;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MaxDifficultyLevel;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MinDifficultyLevel;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bIsPrototype;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bAllowInTestMaps;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bEnabled;
};

USTRUCT(BlueprintType)
struct FFortQuestDrivenMission : public FFortGlobalMission {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortQuestItemDefinition* RequiredQuest;
};

USTRUCT(BlueprintType)
struct FQuestDrivenMissionSubList {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName MissionSubListName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bEnabled;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortQuestDrivenMission> QuestDrivenMissionList;
};

USTRUCT(BlueprintType)
struct FFortNonPrimaryMission {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;
    
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery ContextTagQuery;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FDataTableRowHandle MinDifficulty;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FDataTableRowHandle MaxDifficulty;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	bool bSatisfiesCurrentRequirement;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<int32> RequirementIndicesSatisfied;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<int32> DistributionCategoryIndicesSatisfied;
};

USTRUCT(BlueprintType)
struct FFortMissionDistributionCategory {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery CategoryTagQuery;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortMissionUIActorHandle {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	TWeakObjectPtr<AActor> AttachedActor;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FVector AttachmentOffset;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MaxVisibleDistance;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGuid MissionGuid;
    
	UPROPERTY(EditAnywhere, NotReplicated, Transient, meta=(AllowPrivateAccess=true))
	TWeakObjectPtr<UFortMissionInfoIndicator> MissionUIIndicator;
};

USTRUCT(BlueprintType)
struct FEarnedBadgePlayerData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	FUniqueNetIdRepl PlayerID;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	int32 Count;
};

USTRUCT(BlueprintType)
struct FEarnedBadgeEntry : public FFastArraySerializerItem {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	UFortBadgeItemDefinition* Badge;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<FEarnedBadgePlayerData> PlayerData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortRewardType::Type> RewardType;
};

USTRUCT(BlueprintType)
struct FEarnedBadgeEntryArray : public FFastArraySerializer {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FEarnedBadgeEntry> Items;
};

USTRUCT(BlueprintType)
struct FFortPossibleMission {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Weight;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 MinAlwaysGenerated;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bIsPrototype;
};

USTRUCT(BlueprintType)
struct FFortMissionWeightedReward {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName LootTierGroup;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush LootIcon;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Weight;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortMissionWeightedRewards : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortMissionWeightedReward> Rewards;
};

USTRUCT(BlueprintType)
struct FFortMissionPlacementActorPreferredTagInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FDataTableRowHandle DifficultyInfo;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer PlacementActorPreferredTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	float Difficulty;
};

USTRUCT(BlueprintType)
struct FFortMissionFocusDisplayData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText CurrentFocusDisplayText;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float CurrentFocusPercentage;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortMissionEventName : public FFortEventName {
	GENERATED_BODY()
public:
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortMissionEvent {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName EventType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer ObjectiveHandle;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UObject* EventFocus;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UDataAsset* EventContent;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	AActor* EventInstigator;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 GenericInt;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float GenericFloat;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FText GenericText;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer GameplayTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGuid MissionGuid;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortMissionEventParams* Params;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGeneratedEncounterSequence {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortEncounterTransitionSettings TransitionSettings;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 StartingGeneratedEncounterProfileIndex;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 NumEncountersInSequence;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer EncounterSequenceTags;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGeneratedEncounterOption {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortDifficultyOptionCategoryEncounter* EncounterOptionCategory;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<UFortDifficultyOptionEncounter> EncounterOption;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortDifficultyOptionEncounter* EncounterOptionInstance;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float RangeLerpValue;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bChangedSinceLastVLog;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortEncounterModeSettings {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortEncounterPacingMode::Type> PacingMode;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortEncounterSpawnLocationManagementMode SpawnLocationManagementMode;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortEncounterSpawnLocationPlacementMode::Type> SpawnLocationMode;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortEncounterUtilitiesMode::Type> UtilitiesMode;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortEncounterSpawnLimitType::Type> SpawnLimitMode;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGeneratedEncounterProfile {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float EncounterDifficultyLevel;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortGeneratedEncounterOption> EncounterOptions;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortEncounterModeSettings EncounterModeSettings;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer EncounterTypeTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 DifficultyOptionPointsAvailableAtGeneration;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 MinDifficultyOptionPointsToUse;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bShouldReselectOptionsPerInstance;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	int32 GeneratedEncounterIndex;
};



