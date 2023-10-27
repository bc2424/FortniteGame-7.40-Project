// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// Pre-included headers
#include "Net/UnrealNetwork.h"
#include "Components/SceneComponent.h"
#include "Styling/SlateBrush.h"
#include "GameplayTags.h"
#include "Engine/CurveTable.h"
#include "Materials/MaterialInstance.h"
#include "AI/HotSpots/AIHotSpotConfig.h"
#include "FortniteGame.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogFortWorld, Log, All);

UENUM(BlueprintType)
enum class EAbilitySystemComponentCreationPolicy : uint8 {
	Never,
	Lazy,
	Always,
};

UENUM(BlueprintType)
enum class EFortSharedAnimationState : uint8 {
	Anim_Walk,
	Anim_Run,
	Anim_Turn,
	Anim_Attack,
	Anim_Death,
	Anim_Knockback,
	Anim_FullBodyHit,
	Anim_Pushed,
	Anim_Dance,
	Anim_Idle,
	Anim_RangedAttack,
	Anim_MAX UMETA(Hidden)
};

UENUM(BlueprintType)
namespace EMissionGenerationCategory {
	enum Type {
		Primary,
		Secondary,
		Tertiary,
		Survivor,
		Max_None,
	};
}
UENUM(BlueprintType)
namespace EFortObjectiveRequirement {
	enum Type {
		Optional,
		Required,
		RequiredButCanFail,
	};
}

UENUM(BlueprintType)
enum class EFortObjectiveStatus : uint8 {
	Created,
	InProgress,
	Succeeded,
	Failed,
	NeutralCompletion,
	Max_None,
};

UENUM(BlueprintType)
namespace EFortEncounterPacingMode {
	enum Type {
		SpawnPointsPercentageCurve,
		IntensityCurve,
		Burst,
		Fixed,
	};
}

UENUM(BlueprintType)
namespace EFortEncounterUtilitiesMode {
	enum Type {
		LockedOnly,
		LockedAndFree,
	};
}

UENUM(BlueprintType)
namespace EFortIntensityCurveSequenceType {
	enum Type {
		Sequence,
		Loop,
		Random,
		Max_None,
	};
}

UENUM(BlueprintType)
enum class EFortAIDirectorEventContribution : uint8 {
	Increment,
	Set,
};

UENUM(BlueprintType)
enum class EFortAIDirectorEventParticipant : uint8 {
	Target,
	Source,
	Either,
	Max_None,
};

UENUM(BlueprintType)
enum class ERiftCosmeticState : uint8 {
	None,
	Intro,
	Idle,
	RampUp,
	ShouldDie,
};

UENUM(BlueprintType)
namespace EFortRewardType {
	enum Type {
		Default,
		Missed,
		Max_None,
	};
}

UENUM(BlueprintType)
enum class EFortCompletionResult : uint8 {
	Win,
	Loss,
	Draw,
	Undefined,
};

UENUM(BlueprintType)
namespace EFortRiftSlotStatus {
	enum Type {
		Reserved,
		Occupied,
		Max_None,
	};
}

UENUM(BlueprintType)
enum class EFortRiftSpawnSlotSelectionMode : uint8 {
	Random,
	BestScore,
};

UENUM(BlueprintType)
enum class EFortAIDirectorEvent : uint8 {
	PlayerAIEnemies,
	PlayerTakeDamage,
	PlayerHealth,
	PlayerDeath,
	PlayerLookAtAIEnemy,
	PlayerDamageAIEnemy,
	PlayerKillAIEnemy,
	PlayerHealingPotential,
	PlayerAmmoLight,
	PlayerAmmoMedium,
	PlayerAmmoHeavy,
	PlayerAmmoShells,
	PlayerAmmoEnergy,
	PlayerAINear,
	PlayerMovement,
	ObjectiveTakeDamage,
	ObjectiveHealth,
	ObjectiveDestroyed,
	TrapFired,
	TrapDamagedAIEnemy,
	ObjectivePathCost,
	PlayerPathCost,
	ObjectiveNearbyBuildingDamaged,
	Max_None,
};

UENUM(BlueprintType)
namespace EFortAIDirectorFactorContribution {
	enum Type {
		Direct,
		Inverse,
	};
}

UENUM(BlueprintType)
enum class EFortAIDirectorFactor : uint8 {
	PlayerDamageThreat,
	ObjectiveDamageThreat,
	ObjectivePathCost,
	PlayerPathCost,
	PlayerMovement,
	TrapsEffective,
	PlayerWander,
	NearbyEnemyPresence,
	OffensiveResources,
	DefensiveResources,
	Boredom,
	ArtilleryVulnerability,
	Max_None,
};

UENUM(BlueprintType)
enum class EFortMinigameState : uint8 {
	PreGame,
	Setup,
	Transitioning,
	WaitingForCameras,
	Warmup,
	InProgress,
	PostRoundEnd,
	PostGameEnd,
	PostGameAbandon,
	PostGameReset,
};

UENUM(BlueprintType)
namespace EFortEncounterUtilityDesire {
	enum Type {
		Low,
		Medium,
		High,
		VeryHigh,
		Max_None,
	};
}

UENUM(BlueprintType)
namespace EFortEncounterDirection {
	enum Type {
		North,
		NorthEast,
		East,
		SouthEast,
		South,
		SouthWest,
		West,
		NorthWest,
		Max_None,
	};
}

UENUM(BlueprintType)
enum class EAssignmentCreationResult : uint8 {
	AssignmentNotFoundOrCreated,
	AssignmentCreated,
	AssignmentFound,
};


UENUM(BlueprintType)
enum class EFortEncounterSpawnLocationManagementMode : uint8 {
	Spawn,
	Search,
};

UENUM(BlueprintType)
enum class EAssignmentType : uint8 {
	Invalid,
	Encounter,
	World,
	Enemy,
	NumAssignmentTypes,
};


UENUM(BlueprintType)
enum class EFortReportDayPhase : uint8 {
	Dawn,
	Dusk,
	ZoneFinished,
	PlayerLogout,
};

UENUM(BlueprintType)
enum class EFOBFileHeaderStatus : uint8 {
	NoExistingFile,
	HasExistingFile,
	UnableToDetermine,
};

UENUM(BlueprintType)
enum class EFOBIOStatus : uint8 {
	Saving,
	Loading,
	Free,
};


UENUM(BlueprintType)
enum class EFOBMode : uint8 {
	Uninitialized,
	Creation,
	Deployment,
};


UENUM(BlueprintType)
namespace EFortEncounterSpawnLimitType {
	enum Type {
		NoLimit,
		NumPawnsLimit,
		SpawnPointLimit,
		UserDefined,
		MAX,
	};
}

UENUM(BlueprintType)
namespace EFortEncounterSpawnLocationPlacementMode {
	enum Type {
		Directional,
		Ring,
		Volume,
		Custom,
		Max_None,
	};
}

UENUM(BlueprintType)
enum class EFortMissionStatus : uint8 {
	Created,
	InProgress,
	Succeeded,
	Failed,
	NeutralCompletion,
	Quit,
	Max_None,
};

UENUM(BlueprintType)
namespace ETimerOverrideSetting {
	enum Type {
		DefaultBehavior,
		ForceShow,
		ForceHide,
		ShowAtEnd,
	};
}

UENUM(BlueprintType)
enum class EFortMissionAudibility : uint8 {
	UseVisibility,
	Audible,
	Inaudible,
};


UENUM(BlueprintType)
enum class EFortMissionVisibilityOverride : uint8 {
	Visible,
	Invisible,
	Max_None,
};

UENUM(BlueprintType)
enum class EAttributeInitLevelSource : uint8 {
	WorldDifficulty,
	PlayerBuildingSkill,
	AthenaPlaylist,
};

UENUM(BlueprintType)
namespace EFortBaseWeaponDamage {
	enum Type {
		Combat,
		Environmental,
	};
}


UENUM(BlueprintType)
namespace EFortInventoryType {
	enum Type {
		World,
		Account,
		Outpost,
		MAX,
	};
}


UENUM(BlueprintType)
enum class ENavigationObstacleOverride : uint8 {
	UseMeshSettings,
	ForceEnabled,
	ForceDisabled,
};

UENUM(BlueprintType)
namespace EFortTeam {
	enum Type {
		Spectator,
		HumanCampaign,
		Monster,
		HumanPvP_Team1,
		HumanPvP_Team2,
		MAX = 0xFF,
	};
}

UENUM(BlueprintType)
enum class EPlaysetOffsetType : uint8 {
	CustomOffsetFromCorner,
	Center,
};

UENUM(BlueprintType)
enum class EFortMinigameStatScope : uint8 {
	Group,
	Team,
	Player,
};

UENUM(BlueprintType)
enum class EFortMinigameStatOperation : uint8 {
	Equal,
	Less,
	Greater,
	LessOrEqual,
	GreaterOrEqual,
};

UENUM(BlueprintType)
enum class EMinigameTeamListType : uint8 {
	Blacklist,
	Whitelist,
};

UENUM(BlueprintType)
enum class EFortMinigameEnd : uint8 {
	AbandonGame,
	EndGame,
	EndRound,
	
};
UENUM(BlueprintType)
enum class EFortMinigameExec : uint8 {
	Yes,
	No,
};


UENUM(BlueprintType)
enum class EFortMinigamePostGameSpawnLocationSetting : uint8 {
	IslandStart,
	PreGameLocation,
};

UENUM(BlueprintType)
enum class EFortMinigamePlayerSpawnLocationSetting : uint8 {
	SpawnPads,
	Air,
	CurrentLocation,
};

UENUM(BlueprintType)
enum class EVolumeState : uint8 {
	Uninitialized,
	ReadOnly,
	Initializing,
	Ready,
};

UENUM(BlueprintType)
enum class EMissionStormShieldState : uint8 {
	IDLE,
	GROWING,
	SHRINKING,
	MAX,
};

UENUM(BlueprintType)
namespace EFortBuildingType {
	enum Type {
		Wall,
		Floor,
		Corner,
		Deco,
		Prop,
		Stairs,
		Roof,
		Pillar,
		SpawnedItem,
		Container,
		Trap,
		GenericCenterCellActor,
		None,
	};
}


UENUM(BlueprintType)
namespace EDynamicBuildingPlacementType {
	enum Type {
		CountsTowardsBounds,
		DestroyIfColliding,
		DestroyAnythingThatCollides,
	};
}

UENUM(BlueprintType)
enum class EFortTheaterType : uint8 {
	Standard,
	Elder,
	PvP,
	PvP2,
	Tutorial,
	TutorialGate,
	Max_None,
};

UENUM(BlueprintType)
enum class EFortQuestObjectiveItemEvent : uint8 {
	Craft,
	Collect,
	Acquire,
	Consume,
	OpenCardPack,
	PurchaseCardPack,
	Convert,
	Upgrade,
	UpgradeRarity,
	QuestComplete,
	AssignWorker,
	LevelUpCollectionBook,
	LevelUpAthenaSeason,
	LevelUpBattlePass,
	GainAthenaSeasonXp,
	HasItem,
	HasAccumulatedItem,
	SlotInCollection,
	AlterationRespec,
	AlterationUpgrade,
	HasCompletedQuest,
	HasAssignedWorker,
	HasUpgraded,
	HasConverted,
	HasUpgradedRarity,
	HasLeveledUpCollectionBook,
	SlotHeroInLoadout,
	HasLeveledUpAthenaSeason,
	HasLeveledUpBattlePass,
	HasGainedAthenaSeasonXp,
	MinigameTime,
	Max_None,
};

UENUM(BlueprintType)
enum class EPropertyOverrideTargetType : uint8 {
	None,
	Default,
	ImmutableTarget,
};

UENUM(BlueprintType)
enum class EMinigameFullscreenMapWidgetType : uint8 {
	Default_Map,
	Creative_Scoreboard,
};

UENUM(BlueprintType)
enum class EFortQuestObjectiveStatEvent : uint8 {
	Kill,
	TeamKill,
	KillContribution,
	Damage,
	Damage_OLD,
	Visit,
	Land,
	Emote,
	Spray,
	Toy,
	Build,
	BuildingEdit,
	BuildingRepair,
	BuildingUpgrade,
	PlaceTrap,
	Complete,
	Craft,
	Collect,
	Win,
	Interact,
	TeamInteract,
	Destroy,
	Ability,
	WaveComplete,
	Custom,
	ComplexCustom,
	Client,
	AthenaRank,
	AthenaOutlive,
	RevivePlayer,
	Heal,
	EarnVehicleTrickPoints,
	VehicleAirTime,
	TimeElapsed,
	NumGameplayEvents,
	Acquire,
	Consume,
	OpenCardPack,
	PurchaseCardPack,
	Convert,
	Upgrade,
	UpgradeRarity,
	QuestComplete,
	AssignWorker,
	CollectExpedition,
	CollectSuccessfulExpedition,
	LevelUpCollectionBook,
	LevelUpAthenaSeason,
	LevelUpBattlePass,
	GainAthenaSeasonXp,
	HasItem,
	HasAccumulatedItem,
	SlotInCollection,
	AlterationRespec,
	AlterationUpgrade,
	HasCompletedQuest,
	HasAssignedWorker,
	HasUpgraded,
	HasConverted,
	HasUpgradedRarity,
	HasLeveledUpCollectionBook,
	SlotHeroInLoadout,
	HasLeveledUpAthenaSeason,
	HasLeveledUpBattlePass,
	HasGainedAthenaSeasonXp,
	MinigameDynamicEvent,
	MinigameComplete,
	MinigameDeath,
	MinigameAssist,
	Max_None,
};

UENUM(BlueprintType)
enum class EFortQuestState : uint8 {
	Inactive,
	Active,
	Completed,
	Claimed,
};


UENUM(BlueprintType)
namespace EFortCombatEvents {
	enum Type {
		HuskFollowing,
		SmasherFollowing,
		TrollFollowing,
		FlingerFollowing,
		TakerFollowing,
		HuskCombatNearby,
		SmasherCombatNearby,
		TrollCombatNearby,
		FlingerCombatNearby,
		TakerCombatNearby,
		PlayerTakeDamage,
		PlayerHealth,
		PlayerLookAtEnemy,
		PlayerDamageEnemy,
		PlayerKilledEnemy,
		AtlasTakeDamage,
		AtlasHealth,
		AtlasDestroyed,
		TrapFiring,
		BuildingTakeDamage,
		FoodHealingPotential,
		PlayerAmmo,
		EnemiesNear,
		PlayerMovement,
		BuildingDamagedNearObjective,
		TrapDamageEnemy,
		ObjectivePathCost,
		PlayerPathCost,
		Max_None,
	};
}

UENUM(BlueprintType)
namespace EFortCombatThresholds {
	enum Type {
		Low,
		Medium,
		High,
		Extreme,
		Max_None,
	};
}

UENUM(BlueprintType)
namespace EFortMusicCombatIntensity {
	enum Type {
		Low,
		Medium,
		High,
		VeryHigh,
		Max_None,
	};
}

UENUM(BlueprintType)
enum class EDeployableBaseBuildingState : uint8 {
	Empty,
	Built,
	Unoccupied,
	WaitingToBuild,
	Building,
	WaitingToDestroy,
	Destroying,
	WaitingToReset,
	Resetting,
};

UENUM(BlueprintType)
enum class EDeployableBaseUseType : uint8 {
	Neighborhood,
	PvECombat,
};

UENUM(BlueprintType)
enum class EFortZoneType : uint8 {
	PVE,
	PVP,
	Keep,
	SingleZone,
	Max_None,
};

UENUM(BlueprintType)
enum class ECollectionSelectionMethod : uint8 {
	TierAsIndex,
	TierAsIndexOverflowToLastValid,
	Modulo,
	Random,
	None,
};


UENUM(BlueprintType)
namespace EFortBuildingPersistentState {
	enum Type {
		Default,
		New,
		Constructed,
		Destroyed,
		Searched,
		None,
	};
}

UENUM(BlueprintType)
enum class EFortMusicSectionStopBehavior : uint8 {
	Crossfade,
	AllowFadeOut,
};

UENUM(BlueprintType)
enum class EFortTheaterMapTileType : uint8 {
	Normal,
	CriticalMission,
	AlwaysActive,
	Outpost,
	NonMission,
	PvPFOB,
};

UENUM(BlueprintType)
enum class EFortScriptedActionSource : uint8
{
	Quest                          = 0,
	Token                          = 1,
	Manual                         = 2,
	Max_None                       = 3 UMETA(Hidden),
	EFortScriptedActionSource_MAX  = 4 UMETA(Hidden)
};

UENUM(BlueprintType)
namespace EFortResourceType {
	enum Type {
		Wood,
		Stone,
		Metal,
		Permanite,
		None,
	};
}

UENUM(BlueprintType)
enum class ESavedSupportStatus : uint8 {
	UnknownState,
	Supported,
	UnSupported,
};

UENUM(BlueprintType)
enum class EObjectiveStatusUpdateType : uint8
{
	Always                         = 0,
	OnPercent                      = 1,
	OnComplete                     = 2,
	Never                          = 3,
	EObjectiveStatusUpdateType_MAX = 4 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortQuestType : uint8
{
	Task                           = 0,
	Optional                       = 1,
	DailyQuest                     = 2,
	TransientQuest                 = 3,
	SurvivorQuest                  = 4,
	Achievement                    = 5,
	Onboarding                     = 6,
	StreamBroadcaster              = 7,
	StreamViewer                   = 8,
	StreamSubscriber               = 9,
	Athena                         = 10,
	AthenaDailyQuest               = 11,
	AthenaEvent                    = 12,
	AthenaChallengeBundleQuest     = 13,
	All                            = 14,
	EFortQuestType_MAX             = 15 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EUFortMatchmakingKnobsDataSource : uint8
{
	None                           = 0,
	Playlist                       = 1,
	Mutator                        = 2,
	GameMode                       = 3,
	Permissions                    = 4,
	UISettings                     = 5,
	CreativeGlobalOption           = 6,
	Max                            = 7 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortDecoPlacementQueryResults : uint8
{
	CanAdd                         = 0,
	ExistingTrap                   = 1,
	ExistingObject                 = 2,
	Obstructed                     = 3,
	NoLocation                     = 4,
	WrongType                      = 5,
	WrongShape                     = 6,
	BeingModified                  = 7,
	WrongTeam                      = 8,
	BlueprintFailure               = 9,
	AbilityFailure                 = 10,
	RequiresPlayerBuildableActor   = 11,
	NoEditPermission               = 12,
	WrongZone                      = 13,
	EFortDecoPlacementQueryResults_MAX = 14 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EBuildingAttachmentType : uint8
{
	ATTACH_Floor                   = 0,
	ATTACH_Wall                    = 1,
	ATTACH_Ceiling                 = 2,
	ATTACH_Corner                  = 3,
	ATTACH_All                     = 4,
	ATTACH_WallThenFloor           = 5,
	ATTACH_FloorAndStairs          = 6,
	ATTACH_CeilingAndStairs        = 7,
	ATTACH_None                    = 8 UMETA(Hidden),
	ATTACH_MAX                     = 9 UMETA(Hidden),
};


UENUM()
enum class EPlacementType : uint8
{
	Free                           = 0,
	Grid                           = 1,
	None                           = 2,
	EPlacementType_MAX             = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EStructuralSupportCheck : uint8 {
	Stable,
	Unstable,
	Max_None,
};

UENUM(BlueprintType)
enum class EColorSwatchType : uint8
{
	EColorSwatchType_Skin          = 0 UMETA(DisplayName = "Skin"),
	EColorSwatchType_Hair          = 1 UMETA(DisplayName = "Hair"),
	EColorSwatchType_BodyAccessory = 2 UMETA(DisplayName = "BodyAccessory"),
	EColorSwatchType_Accessory     = 3 UMETA(DisplayName = "Accessory"),
	EColorSwatchType_NumTypes      = 4 UMETA(Hidden),
	EColorSwatchType_MAX           = 5 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortScriptedActionEnvironment : uint8
{
	FrontEnd                       = 0,
	GameServer                     = 1,
	GameClient                     = 2,
	Max_None                       = 3 UMETA(Hidden),
	EFortScriptedActionEnvironment_MAX = 4 UMETA(Hidden),
};

UENUM(BlueprintType)//Fake Enum from Common UI as private plugin
enum class ECommonInputType : uint8
{
	MouseAndKeyboard,
	Gamepad,
	Touch,
	Count,
};

UENUM(BlueprintType)
enum class EAthenaRewardItemType : uint8
{
	Normal = 0,
	HiddenReward = 1,
	NonExportedFakeReward = 2
};

UENUM(BlueprintType)
enum class EFortMontageInputType : uint8
{
	WindowClickOrHold              = 0,
	WindowHoldOnly                 = 1,
	InstantClick                   = 2,
	EFortMontageInputType_MAX      = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortGliderType : uint8
{
	Glider                         = 0,
	Umbrella                       = 1,
	EFortGliderType_MAX            = 2 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortFootstepSurfaceType : uint8
{
	Default                        = 0,
	Wood                           = 1,
	Stone                          = 2,
	Metal                          = 3,
	Water                          = 4,
	Snow                           = 5,
	Ice                            = 6,
	Lava                           = 7,
	Max_None                       = 8 UMETA(Hidden),
	EFortFootstepSurfaceType_MAX   = 9 UMETA(Hidden),
};


UENUM(BlueprintType)
enum class EChallengeBundleQuestUnlockType : uint8
{
	GrantWithBundle                = 0,
	RequiresBattlePass             = 1,
	DaysFromEventStart             = 2,
	EChallengeBundleQuestUnlockType_MAX = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EChallengeScheduleUnlockType : uint8
{
	Manually                       = 0,
	OnScheduleGranted              = 1,
	DaysSinceEventStart            = 2,
	EChallengeScheduleUnlockType_MAX = 3 UMETA(Hidden)
};


UENUM(BlueprintType)
enum class ELayeredAudioTriggerDirection : uint8
{
	AnyDirection                   = 0,
	Forwards                       = 1,
	Sideways                       = 2,
	Backwards                      = 3,
	Count                          = 4,
	ELayeredAudioTriggerDirection_MAX = 5 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortWeaponTriggerType : uint8
{
	OnPress = 0,
	Automatic = 1,
	OnRelease = 2,
	OnPressAndRelease = 3,
	EFortWeaponTriggerType_MAX = 4 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ELayeredAudioTriggerDir : uint8
{
	Forward                        = 0,
	Backward                       = 1,
	ELayeredAudioTriggerDir_MAX    = 2 UMETA(Hidden)
};



UENUM(BlueprintType)
enum class EFortAppliedSwapItemAndVariantState : uint8
{
	None                           = 0,
	Active                         = 1,
	Inactive                       = 2,
	EFortAppliedSwapItemAndVariantState_MAX = 3 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EAthenaChallengeTabVisibility : uint8
{
	Hide = 0,
	ShowAlways = 1
};

UENUM(BlueprintType)
enum class ELayeredAudioInterpolationType : uint8
{
	None                           = 0,
	CustomCurve                    = 1,
	Linear                         = 2,
	ELayeredAudioInterpolationType_MAX = 3 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EGliderTrailAttachmentMode : uint8
{
	GliderMesh                     = 0,
	PlayerPawn                     = 1,
	EGliderTrailAttachmentMode_MAX = 2 UMETA(Hidden)
};


UENUM(BlueprintType)
enum class EGliderTrailActivationMode : uint8
{
	None                           = 0,
	AutoActivate                   = 1,
	FullyDeployed                  = 2,
	EGliderTrailActivationMode_MAX = 3 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ECharacterPartAttachmentTargetType : uint8
{
	RootComponent = 0,
	SkeletalMeshForAssociatedPlayerPawnPartType = 1,
	ECharacterPartAttachmentTargetType_MAX = 2 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EMontageSelectionPredicateType : uint8
{
	NotSet                         = 0,
	MetaTags                       = 1,
	CharacterParts                 = 2,
	ActiveSwapPresence             = 3,
	Invalid                        = 4,
	EMontageSelectionPredicateType_MAX = 5 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ECustomHatType : uint8
{
	ECustomHatType_None            = 0,
	ECustomHatType_Cap             = 1,
	ECustomHatType_Helmet          = 2,
	ECustomHatType_Mask            = 3,
	ECustomHatType_Hat             = 4,
	ECustomHatType_HeadReplacement = 5,
	ECustomHatType_MAX             = 6 UMETA(Hidden)
};


UENUM(BlueprintType)
enum class EFortFeedbackContext : uint8
{
	FFC_Instigator,
	FFC_Recipient,
	FFC_TeamWitness,
	FFC_EnemyWitness,
	FFC_AllPawns,
	FFC_Announcer,
	FFC_None_Max,
	FFC_MAX UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortFeedbackAddressee : uint8
{
	FFA_Instigator                 = 0,
	FFA_Recipient                  = 1,
	FFA_All                        = 2,
	FFA_MAX                        = 3 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortFeedbackBroadcastFilter : uint8
{
	FFBF_Speaker                   = 0,
	FFBF_SpeakerTeam               = 1,
	FFBF_SpeakerAdressee           = 2,
	FFBF_HumanPvP_Team1            = 3,
	FFBF_HumanPvP_Team2            = 4,
	FFBF_None_Max                  = 5,
	FFBF_MAX                       = 6 UMETA(Hidden)
};


UENUM(BlueprintType)
enum class EAthenaSeasonShopVisibility : uint8
{
	Hide = 0,
	ShowIfOffersAvailable = 1,
	ShowAlways = 2
};


UENUM(BlueprintType)
enum class EFortTextureDataType : uint8
{
	Any = 0,
	OuterWall = 1,
	InnerWall = 2,
	Corner = 3,
	Floor = 4,
	Ceiling = 5,
	Trim = 6,
	Roof = 7,
	Pillar = 8,
	Shingle = 9,
	None = 10
};

UENUM()
enum class EFortFacialAnimTypes : uint8
{
	Default,
	FaceOnly,
	FullHead,
	FromAmplitude,
	Max UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortPickupTossState : uint8
{
	NotTossed = 0,
	InProgress = 1,
	AtRest = 2
};

UENUM(BlueprintType)
enum class EFortPickupSpawnSource : uint8
{
	Unset = 0,
	PlayerElimination = 1,
	Chest = 2,
	SupplyDrop = 3,
	AmmoBox = 4
};

UENUM(BlueprintType)
enum class EFortItemEntryState : uint8
{
	NoneState = 0,
	NewItemCount = 1,
	ShouldShowItemToast = 2,
	DurabilityInitialized = 3,
	DoNotShowSpawnParticles = 4,
	FromRecoveredBackpack = 5,
	FromGift = 6,
	PendingUpgradeCriteriaProgress = 7,
	OwnerBuildingHandle = 8,
	FromDroppedPickup = 9,
	JustCrafted = 10,
	CraftAndSlotTarget = 11,
	GenericAttributeValueSet = 12
};


UENUM(BlueprintType)
enum class EFortWeaponReloadType : uint8
{
	ReloadWholeClip = 0,
	ReloadIndividualBullets = 1,
	ReloadBasedOnAmmoCostPerFire = 2,
	ReloadBasedOnCartridgePerFire = 3,
	EFortWeaponReloadType_MAX = 4 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortLevelStreamingState : uint8
{
	LSS_Unloaded = 0,
	LSS_Loaded = 1,
	LSS_UnconditionalFoundationsUpdated = 2,
	LSS_AllFoundationsUpdated = 3,
	LSS_NewActorsCreatedButNotUpdated = 4,
	LSS_AllUpdated = 5,
	LSS_Ready = 6
};

UENUM(BlueprintType)
enum class EFortItemTier : uint8
{
	No_Tier = 0,
	I = 1,
	II = 2,
	III = 3,
	IV = 4,
	V = 5,
	VI = 6,
	VII = 7,
	VIII = 8,
	IX = 9,
	X = 10,
	NumItemTierValues = 11 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortQuality : uint8
{
	Common = 0,
	Uncommon = 1,
	Rare = 2,
	NumQualityValues = 3 UMETA(Hidden)
};

UENUM()
enum EFortTextureDataSlot
{
	Primary,
	Secondary,
	Tertiary,
	Fourth,
	NumSlots UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortProximityBasedGEApplicationType : uint8
{
	ApplyOnProximityPulse = 0,
	ApplyOnProximityTouch = 1,
	ApplyOnlyDuringProximityTouch = 2
};

UENUM(BlueprintType)
enum class EFortMarkedActorScreenClamping : uint8
{
	Default = 0,
	Clamp = 1,
	ClampWhileNew = 2,
	DontClamp = 3
};

UENUM(BlueprintType)
enum class EFortDeliveryInfoBuildingActorSpecification : uint8
{
	All = 0,
	PlayerBuildable = 1,
	NonPlayerBuildable = 2
};

UENUM(BlueprintType)
enum EBuildingFoundationType {
	BFT_3x3,
	BFT_5x5,
	BFT_5x10,
	BFT_None,
	BFT_MAX UMETA(Hidden),
};

UENUM(BlueprintType)
enum EBinaryToggleValues {
	BTV_Active,
	BTV_Inactive,
	BTV_Either,
	BTV_MAX UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EStructuralWallPosition : uint8 {
	Left,
	Right,
	Front,
	Back,
};

UENUM(BlueprintType)
enum class EFortBuildPreviewMarkerOptionalAdjustment : uint8 {
	None,
	FreeWallPieceOnTop,
	FreeWallPieceOnBottom,
};

UENUM(BlueprintType)
enum class EStructuralFloorPosition : uint8 {
	Top,
	Bottom,
};


UENUM(BlueprintType)
namespace EFortStructuralGridQueryResults {
	enum Type {
		CanAdd,
		ExistingActor,
		Obstructed,
		NoStructuralSupport,
		InvalidActor,
		ReachedLimit,
		NoEditPermission,
		PatternNotPermittedByLayoutRequirement,
		ResourceTypeNotPermittedByLayoutRequirement,
		BuildingAtRequirementsDisabled,
		BuildingOtherThanRequirementsDisabled,
	};
}

UENUM(BlueprintType)
enum class EFortDefenderInteractionError : uint8 {
	None,
	Obstructed,
	NoEditPermission,
	UsedByAnotherPlayer,
};

UENUM(BlueprintType)
enum class EFortDefenderSubtype : uint8 {
	AssaultRifle,
	Pistol,
	Melee,
	Sniper,
	Shotgun,
	Invalid,
};

UENUM(BlueprintType)
enum class ERealEstateOffsetType : uint8 {
	CustomOffsetFromCorner,
	Center,
};

UENUM(BlueprintType)
namespace FDynamicBuildOrder {
	enum Type {
		X,
		Y,
		Z,
		None,
	};
}

UENUM(BlueprintType)
enum class EVolumeValidityResult : uint8 {
	Valid,
	Invalid,
};

UENUM(BlueprintType)
enum class EKeepContainerType : uint8 {
	Base,
	Storeroom,
	FirstAid,
	Armory,
	Workshop,
	AmmoStash,
	Max,
};

UENUM(BlueprintType)
namespace EBuildingWallArea {
	enum Type {
		Regular,
		Flat,
		Special,
	};
}

UENUM(BlueprintType)
enum class EFortHomingStyle : uint8 {
	None,
	LockOn,
	LaserTargeted,
	LaserTargeted_NoTrace,
};

UENUM(BlueprintType)
enum class EDynamicFoundationEnabledState : uint8 {
	Unknown,
	Enabled,
	Disabled,
};
UENUM(BlueprintType)
enum class EDynamicFoundationType : uint8 {
	Static,
	StartEnabled_Stationary,
	StartEnabled_Dynamic,
	StartDisabled,
};

UENUM(BlueprintType)
namespace EFortTeamAffiliation {
	enum Type {
		Friendly,
		Neutral,
		Hostile,
	};
}

UENUM(BlueprintType)
namespace EFortBuildingInitializationReason {
	enum Type {
		StaticallyPlaced,
		Spawned,
		Replaced,
		LoadedFromSave,
		DynamicBuilderPlaced,
		PlacementTool,
		TrapTool,
		None,
	};
}

UENUM(BlueprintType)
namespace EFortEncounterPacingState {
	enum Type {
		Ramp,
		Peak,
		Fade,
		Rest,
		Max_None,
	};
}

UENUM(BlueprintType)
namespace EFortEncounterState {
	enum Type {
		Uninitialized,
		InitializingProperties,
		InitializingRiftManager,
		AwaitingActivation,
		Active,
		ReplacingRifts,
		Max_None,
	};
}

UENUM(BlueprintType)
namespace EFortMissionType {
	enum Type {
		Primary,
		Secondary,
		Max_None,
	};
}


UENUM(BlueprintType)
enum class EFortWeaponCoreAnimation : uint8
{
	Melee = 0,
	Pistol = 1,
	Shotgun = 2,
	PaperBlueprint = 3,
	Rifle = 4,
	MeleeOneHand = 5,
	MachinePistol = 6,
	RocketLauncher = 7,
	GrenadeLauncher = 8,
	GoingCommando = 9,
	AssaultRifle = 10,
	TacticalShotgun = 11,
	SniperRifle = 12,
	TrapPlacement = 13,
	ShoulderLauncher = 14,
	AbilityDecoTool = 15,
	Crossbow = 16,
	C4 = 17,
	RemoteControl = 18,
	DualWield = 19,
	AR_BullPup = 20,
	AR_ForwardGrip = 21,
	MedPackPaddles = 22,
	SMG_P90 = 23,
	AR_DrumGun = 24,
	Consumable_Small = 25,
	Consumable_Large = 26,
	Balloon = 27,
	MountedTurret = 28,
	CreativeTool = 29,
	ExplosiveBow = 30,
	AshtonIndigo = 31,
	AshtonChicago = 32,
	MeleeDualWield = 33,
	MAX = 34 UMETA(Hidden)
};

UENUM(BlueprintType)

enum class EFortItemType : uint8
{
	WorldItem                      = 0,
	Ammo                           = 1,
	Badge                          = 2,
	BackpackPickup                 = 3,
	BuildingPiece                  = 4,
	CharacterPart                  = 5,
	Consumable                     = 6,
	Deco                           = 7,
	EditTool                       = 8,
	Ingredient                     = 9,
	ItemCache                      = 10,
	Food                           = 11,
	Gadget                         = 12,
	AthenaGadget                   = 13,
	HomebaseGadget                 = 14,
	HeroAbility                    = 15,
	MissionItem                    = 16,
	Trap                           = 17,
	Weapon                         = 18,
	WeaponMelee                    = 19,
	WeaponRanged                   = 20,
	WeaponHarvest                  = 21,
	WeaponCreativePhone            = 22,
	WorldResource                  = 23,
	CreativeUserPrefab             = 24,
	AccountItem                    = 25,
	AccountResource                = 26,
	CollectedResource              = 27,
	Alteration                     = 28,
	CardPack                       = 29,
	Currency                       = 30,
	Hero                           = 31,
	Schematic                      = 32,
	Worker                         = 33,
	TeamPerk                       = 34,
	Token                          = 35,
	DailyRewardScheduleToken       = 36,
	CodeToken                      = 37,
	Stat                           = 38,
	Buff                           = 39,
	BuffCredit                     = 40,
	Quest                          = 41,
	ChallengeBundle                = 42,
	ChallengeBundleSchedule        = 43,
	GameplayModifier               = 44,
	Outpost                        = 45,
	HomebaseNode                   = 46,
	Defender                       = 47,
	ConversionControl              = 48,
	DeployableBaseCloudSave        = 49,
	ConsumableAccountItem          = 50,
	Quota                          = 51,
	Expedition                     = 52,
	HomebaseBannerIcon             = 53,
	HomebaseBannerColor            = 54,
	AthenaSkyDiveContrail          = 55,
	PersonalVehicle                = 56,
	AthenaGlider                   = 57,
	AthenaPickaxe                  = 58,
	AthenaHat                      = 59,
	AthenaBackpack                 = 60,
	AthenaCharacter                = 61,
	AthenaDance                    = 62,
	AthenaConsumableEmote          = 63,
	AthenaLoadingScreen            = 64,
	AthenaBattleBus                = 65,
	AthenaVehicleCosmetic          = 66,
	AthenaItemWrap                 = 67,
	AthenaCallingCard              = 68,
	AthenaMapMarker                = 69,
	AthenaMusicPack                = 70,
	AthenaPetCosmetic              = 71,
	AthenaVictoryPose              = 72,
	AthenaSeasonTreasure           = 73,
	AthenaSeason                   = 74,
	EventDescription               = 75,
	MatchAward                     = 76,
	AthenaEventToken               = 77,
	EventPurchaseTracker           = 78,
	CosmeticVariantToken           = 79,
	CampaignHeroLoadout            = 80,
	Playset                        = 81,
	PrerollData                    = 82,
	CreativePlot                   = 83,
	PlayerSurveyToken              = 84,
	SpecialItem                    = 85,
	Emote                          = 86,
	Stack                          = 87,
	CollectionBookPage             = 88,
	BGAConsumableWrapper           = 89,
	GiftBox                        = 90,
	Profile                        = 91,
	Max_None                       = 92 UMETA(Hidden),
	EFortItemType_MAX              = 93 UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFortCardinalDirection : uint8
{
	North = 0,
	East = 1,
	South = 2,
	West = 3
};

UENUM(BlueprintType)
enum class EAthenaGamePhase : uint8
{
	None = 0,
	Setup = 1,
	Warmup = 2,
	Aircraft = 3,
	SafeZones = 4,
	EndGame = 5,
	Count = 6,
	EAthenaGamePhase_MAX = 7 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortRarity : uint8
{
	Common = 1 UMETA(DisplayName = "Common (Grey)"),
	Uncommon = 0 UMETA(DisplayName = "Uncommon (Green)"),
	Rare = 2 UMETA(DisplayName = "Rare (Blue)" ),
	Epic = 3 UMETA(DisplayName = "Epic (Purple)"),
	Legendary = 4 UMETA(DisplayName = "Legendary (Orange)"),
	Mythic = 5 UMETA(DisplayName = "Mythic (Yellow)"),
	Transcendent = 6 UMETA(DisplayName = "Transcendent (Pinkish)"),
	Unattainable = 7 UMETA(DisplayName = "Unattainable"),
	NumRarityValues = 10 UMETA(Hidden),
	EFortRarity_MAX = 11 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFriendlyFireType : uint8
{
	Off = 0,
	On = 1
};

UENUM(BlueprintType)
enum class EDBNOType : uint8
{
	On = 0,
	Off = 1,
	NotWhenRespawning = 2
};

UENUM(BlueprintType)
enum class EAthenaRespawnType : uint8
{
	None = 0,
	InfiniteRespawn = 1,
	InfiniteRespawnExceptStorm = 2,
	EAthenaRespawnType_MAX = 3
};


UENUM(BlueprintType)
enum class EAirCraftBehavior : uint8
{
	Default = 0,
	OpposingAirCraftForEachTeam = 1,
	FlyTowardFirstCircleCenter = 2,
	NoAircraft = 3,
	EAirCraftBehavior_MAX = 4
};

UENUM(BlueprintType)
enum class ESafeZoneStartUp : uint8
{
	UseDefaultGameBehavior = 0,
	StartsWithWarmUp = 1,
	StartsWithAirCraft = 2,
	ESafeZoneStartUp_MAX = 3
};

UENUM(BlueprintType)
enum class EForceKickAfterDeathMode : uint8
{
	Disabled = 0,
	KickAll = 1,
	KickPrivate = 2,
	EForceKickAfterDeathMode_MAX = 3
};

UENUM(BlueprintType)
enum class EWeaponSelectionPreservationType : uint8
{
	KeepSelectionWhenRespawning = 0,
	NeverKeepSelection = 1,
	EWeaponSelectionPreservationType_MAX = 2
};

UENUM(BlueprintType)
enum class ERewardPlacementBonusType : uint8
{
	Solo = 0,
	Duo = 1,
	Squad = 2,
	LargeTeam = 3,
	None = 4,
	TwoTeam = 5,
	MediumTeam = 6,
	QuickSolo = 7,
	QuickDuo = 8,
	QuickSquad = 9,
	QuickLargeTeam = 10,
	QuickTwoTeam = 11,
	QuickMediumTeam = 12,
	SinglePlacement = 13,
	ERewardPlacementBonusType_MAX = 14
};

UENUM(BlueprintType)
enum class EPlaylistUIExtensionSlot : uint8 {
	Primary,
	TopRightCorner,
	GameInfoBox,
	Quickbar,
	UpperCenter,
	CrosshairRight,
	UnderSquadInfo,
	FullScreenMap,
	BelowRespawnWidget,
	BelowCompass,
	UnderTeammateStatus,
};

UENUM(BlueprintType)
enum class EAthenaScoringEvent : uint8
{
	None = 0,
	Elimination = 1,
	ChestOpened = 2,
	AmmoCanOpened = 3,
	SupplyDropOpened = 4,
	SupplyLlamaOpened = 5,
	ForagedItemConsumed = 6,
	SurvivalInMinutes = 7,
	CollectedCoinBronze = 8,
	CollectedCoinSilver = 9,
	CollectedCoinGold = 10,
	AIKilled = 11,
	EAthenaScoringEvent_MAX = 12
};

UENUM(BlueprintType)
enum class ERewardTimePlayedType : uint8
{
	Default = 0,
	NoReward = 1,
	FlatValue = 2,
	ERewardTimePlayedType_MAX = 3
};

UENUM(BlueprintType)
enum class EAthenaWinCondition : uint8
{
	LastManStanding = 0,
	LastManStandingIncludingAllies = 1,
	TimedTeamFinalFight = 2,
	FirstToGoalScore = 3,
	TimedLastMenStanding = 4,
	MutatorControlled = 5,
	MutatorControlledGoalScore = 6,
	EAthenaWinCondition_MAX = 7
};

UENUM(BlueprintType)
enum class EFortCustomPartType : uint8
{
	Head                           = 0,
	Body                           = 1, 
	Hat                            = 2,
	Backpack                       = 3, 
	Charm                          = 4,
	Face                           = 5,
	NumTypes                       = 6,
	EFortCustomPartType_MAX        = 7 
};

UENUM(BlueprintType)
enum class EFortVariantTokenEquipRule : uint8
{
	EquipBaseVariantOnly = 0,
	AlsoEquipAdditionalGrants = 1,
	AlsoEquipPreviewGrantsIfOwned = 2,
	EquipAllExceptUnowned = 3,
	EFortVariantTokenEquipRule_MAX = 4
};

UENUM(BlueprintType)
enum class EFortTemplateAccess : uint8 
{
	Normal = 0,
	Trusted = 1,
	Private = 2,
	EFortTemplateAccess_MAX = 3,
};

UENUM(BlueprintType)
enum class ELoadoutVariantInsertType : uint8 
{
	StartOfArray,
	EndOfArray,
	ELoadoutVariantInsertType_MAX,
};

UENUM(BlueprintType)
enum class EItemWrapMaterialType : uint8
{
	WeaponWrap = 0,
	VehicleWrap_Opaque = 1,
	VehicleWrap_Masked = 2,
	Character = 3,
	EItemWrapMaterialType_MAX = 4
};
UENUM(BlueprintType)
enum class ECosmeticMetaTagRequirementCategory : uint8
{
	None = 0,
	Glider = 1,
	Pickaxe = 2,
	Backpack = 3,
	Character = 4,
	FullLoadout = 5,
	MAX = 6
};

UENUM(BlueprintType)
enum class EFortRichColorConflictResolutionRules : uint8
{
	NoConflictsAllowed = 0,
	BlackOrWhiteCannotConflict = 1,
	MinimumDistanceBlackOrWhite = 2,
	MinimumContrast = 3,
	MinimumContrastOrHueSaturationShift = 4,
	MinimumContrastGrayscale = 5,
	EFortRichColorConflictResolutionRules_MAX = 6
};

UENUM(BlueprintType)
enum class EFortCustomGender : uint8
{
	Invalid = 0,
	Male = 1,
	Female = 2,
	Both = 3,
	EFortCustomGender_MAX = 4
};
UENUM(BlueprintType)
enum class EAnimInstanceClassSwapType : uint8
{
	None = 0,
	SwapOnMatch = 1,
	EAnimInstanceClassSwapType_MAX = 2
};

UENUM()
enum class EFortAlteration : uint8
{
	GameplaySlot,
	ComplexCosmeticSlot,
	UserPickedCosmeticSlot,
	ColorSlot,
	HeroSpecializationTier1Slot,
	HeroSpecializationTier2Slot,
	HeroSpecializationTier3Slot,
	HeroSpecializationTier4Slot,
	HeroSpecializationTier5Slot,
	EFortAlteration_MAX,
};

UENUM()
enum class EFortCustomBodyType : uint8 {
	NONE,
	Small,
	Medium,
	MediumAndSmall,
	Large,
	LargeAndSmall,
	LargeAndMedium,
	All,
	Deprecated,
	EFortCustomBodyType_MAX,
};

UENUM()
enum class ESubGame : uint8 
{
	Campaign,
	Athena,
	Invalid,
	Count,
	Creative,
	ESubGame_MAX,
};

UENUM()
enum class EFortGiftWrapType : uint8 
{
	System,
	UserFree,
	UserUnlock,
	UserConsumable,
	Message,
	Ungift,
	EFortGiftWrapType_MAX,
};

UENUM()
enum class EAthenaRewardVisualImportanceType : uint8 
{
	Normal,
	Hot,
	CrazyHot,
	Crazy,
	EAthenaRewardVisualImportanceType_MAX,
};
UENUM()
enum class EItemProfileType : uint8 
{
	Common,
	Campaign,
	Athena,
	EItemProfileType_MAX,
};
UENUM()
enum class EMontageVisibilityRule : uint8 
{
	RequiredItem,
	ForbiddenItem,
	EMontageVisibilityRule_MAX,
};

UENUM()
enum class EFXType : uint8 
{
	GenericAnimNotify,
	TrailAnimNotify,
	WeaponImpactEffect,
	WeaponMeleeImpactEffect,
	Contrail,
	Emote,
	Trap,
	Skin,
	Glider,
	Vehicle,
	BackpackBling,
	Water,
	LootChest,
	EnvironmentalAmbient,
	WeaponRangedBeam,
	WeaponBulletShells,
	WeaponMuzzleFlashes,
	PickAxe,
	Curie,
	Projectile,
	EFXType_MAX,
};

UENUM()
enum class EVariantUnlockType : uint8 
{
	UnlockAll,
	ExclusiveChoice,
	EVariantUnlockType_MAX,
};

UENUM()
enum class EAthenaPetAttachRule : uint8 
{
	AttachToBackpack,
	AttachToBody,
	EAthenaPetAttachRule_MAX,
};

UENUM()
enum class EFortHandIKOverrideType : uint8 
{
	UseDefault,
	ForceFK,
	ForceIK,
	ForceFKSnap,
	EFortHandIKOverrideType_MAX,
};

UENUM()
enum class EFortPlayerAnimBodyType : uint8 
{
	Small,
	Medium,
	Large,
	All,
	EFortPlayerAnimBodyType_MAX,
};

UENUM()
enum class EAnimRelaxedState : uint8 
{
	None,
	WeaponRaised,
	RelaxedLevel1,
	RelaxedLevel2,
	EAnimRelaxedState_MAX,
};

UENUM()
enum class EFortReloadFXState : uint8 
{
	ReloadStart,
	ReloadCartridge,
	ReloadEnd,
	Max_None,
	EFortReloadFXState_MAX,
};

UENUM()
enum class EFortWeaponSoundState : uint8 
{
	Normal,
	LowAmmo,
	Degraded,
	Max_None,
	EFortWeaponSoundState_MAX,
};
UENUM()
enum class EFortDisplayTier : uint8 
{
	Invalid = 0,
	Handmade = 1,
	Copper = 2,
	Silver = 3,
	Malachite = 4,
	Obsidian = 5,
	Brightcore = 6,
	Spectrolite = 7,
	Shadowshard = 8,
	Sunbeam = 9,
	Moonglow = 10,
	EFortDisplayTier_MAX = 11 UMETA(Hidden)
};

UENUM()
enum class EWorldItemDropBehavior : uint8
{
	DropAsPickup = 1,
	DestroyOnDrop = 2,
	DropAsPickupDestroyOnEmpty = 3,
	DropAsPickupEvenWhenEmpty = 4,
	EWorldItemDropBehavior_MAX = 0 UMETA(Hidden, DisplayName = "Default")
};

UENUM(BlueprintType)
enum class ELayoutRequirementStatus : uint8 {
	Inactive_Invisible,
	Active_Invisible,
	Active_Visible,
};

UENUM(BlueprintType)
namespace EFortAIUtility {
	enum Type {
		KillPlayersMelee,
		KillPlayersRanged,
		KillPlayersArtillery,
		DestroyBuildingsMelee,
		DestroyBuildingsRanged,
		DestroyBuildingsArtillery,
		DestroyTraps,
		Tank,
		Infiltrate,
		Mob,
		Support,
		Kiting,
		AreaOfDenial,
		DisableTraps,
		Dormant,
		Assassin,
		MAX,
	};
}

UENUM(BlueprintType)
enum class EFortItemCollectorTrackingType : uint8 {
	Player,
	Team,
};

UENUM(BlueprintType)
enum class EFortItemCollectorBehavior : uint8 {
	FirstToGoal,
	FreeForAll,
};


UENUM(BlueprintType)
enum class EFortItemCollectorState : uint8 {
	CanInteract,
	Active,
	Inactive,
	Captured,
	Invalid,
};

UENUM(BlueprintType)
enum class ESpawnMachineState : uint8 {
	Default,
	WaitingForUse,
	Active,
	Complete,
	OnCooldown,
};

UENUM(BlueprintType)
enum class ESpawnMachineSubTextState : uint8 {
	NoCards,
	VanInUse,
	None,
};

UENUM()
enum class EFortAbilityTargetingSource : uint8
{
	Camera = 1,
	PawnForward = 2,
	PawnTowardsFocus = 3,
	WeaponForward = 4,
	WeaponTowardsFocus = 5,
	Custom = 6,
	Max_None = 7,
	EFortAbilityTargetingSource_MAX = 0 UMETA(Hidden, DisplayName = "Default")
};

UENUM()
enum class EFortFrontendInventoryFilter : uint8
{
	Schematics = 0,
	WorldItems = 1,
	WorldItemsInGame = 2,
	WorldItemsStorage = 3,
	WorldItemsTransfer = 4,
	ConsumablesAndAccountResources = 5,
	Heroes = 6,
	Defenders = 7,
	Survivors = 8,
	AthenaCharacter = 9,
	AthenaBackpack = 10,
	AthenaPickaxe = 11,
	AthenaGliders = 12,
	AthenaContrails = 13,
	AthenaEmotes = 14,
	AthenaItemWraps = 15,
	AthenaLoadingScreens = 16,
	AthenaLobbyMusic = 17,
	HestiaWeapons = 18,
	HestiaResources = 19,
	Invisible = 20,
	Max_None = 21,
	EFortFrontendInventoryFilter_MAX = 22 UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FFortQuestPackInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	FString DefaultQuestPack;

	UPROPERTY(EditAnywhere)
	int MaxActiveDailyQuests;

	UPROPERTY(EditAnywhere)
	int MaxRerollsPerDay;

	UPROPERTY(EditAnywhere)
	int DaysToKeepClaimedQuests;

	UPROPERTY(EditAnywhere)
	int DaysToKeepCompletedQuests;

	UPROPERTY(EditAnywhere)
	int MaxUnclaimedQuests;

	UPROPERTY(EditAnywhere)
	bool IsStreamingQuestPack;
};

UENUM()
enum class EFortInventoryFilter : uint8
{
	WeaponMelee = 0,
	WeaponRanged = 1,
	Ammo = 2,
	Traps = 3,
	Consumables = 4,
	Ingredients = 5,
	Gadget = 6,
	Decorations = 7,
	Badges = 8,
	Heroes = 9,
	LeadSurvivors = 10,
	Survivors = 11,
	Defenders = 12,
	Resources = 13,
	ConversionControl = 14,
	AthenaCosmetics = 15,
	Playset = 16,
	CreativePlot = 17,
	TeamPerk = 18,
	Workers = 19,
	Invisible = 20,
	Max_None = 21,
	EFortInventoryFilter_MAX = 22 UMETA(Hidden)
};

UENUM()
enum class EAthenaGamePhaseStep : uint8
{
	None                           = 0,
	Setup                          = 1,
	Warmup                         = 2,
	GetReady                       = 3,
	BusLocked                      = 4,
	BusFlying                      = 5,
	StormForming                   = 6,
	StormHolding                   = 7,
	StormShrinking                 = 8,
	Countdown                      = 9,
	FinalCountdown                 = 10,
	EndGame                        = 11,
	Count                          = 12,
	EAthenaGamePhaseStep_MAX       = 13 UMETA(Hidden),
};

UENUM()
enum class EFortReplicatedStat : uint8
{
	MonsterKills = 0,
	MonsterDamagePoints = 1,
	PlayerKills = 2,
	WoodGathered = 3,
	StoneGathered = 4,
	MetalGathered = 5,
	Deaths = 6,
	BuildingsBuilt = 7,
	BuildingsBuilt_Wood = 8,
	BuildingsBuilt_Stone = 9,
	BuildingsBuilt_Metal = 10,
	BuildingsUpgraded_Wood2 = 11,
	BuildingsUpgraded_Wood3 = 12,
	BuildingsUpgraded_Stone2 = 13,
	BuildingsUpgraded_Stone3 = 14,
	BuildingsUpgraded_Metal2 = 15,
	BuildingsUpgraded_Metal3 = 16,
	BuildingsDestroyed = 17,
	Repair_Wood = 18,
	Repair_Stone = 19,
	Repair_Metal = 20,
	FlagsCaptured = 21,
	FlagsReturned = 22,
	ContainersLooted = 23,
	CraftingPoints = 24,
	TrapPlacementPoints = 25,
	TrapActivationPoints = 26,
	TotalScore = 27,
	OldTotalScore = 28,
	CombatScore = 29,
	BuildingScore = 30,
	UtilityScore = 31,
	BadgesScore = 32,
	None = 33,
	MAX = 34 UMETA(Hidden),
};

UENUM(BlueprintType)
namespace EBuildingStairsRailing {
	enum Type {
		None,
		Partial,
		Full,
	};
}

UENUM()
enum class EFortReplenishmentType : uint8
{
	Restricted = 0,
	ClampMin = 1,
	Add = 2,
	Ability = 3,
	EFortReplenishmentType_MAX = 4 UMETA(Hidden),
};

UENUM()
enum class EStatCategory : uint8
{
	Combat                         = 0,
	Building                       = 1,
	Utility                        = 2,
	Max_None                       = 3,
	EStatCategory_MAX              = 4 UMETA(Hidden),
};

UENUM()
enum class EFortDisplayGender : uint8
{
	Unknown                        = 0,
	Male                           = 1,
	Female                         = 2,
	NumTypes                       = 3,
	EFortDisplayGender_MAX         = 4 UMETA(Hidden),
};


UENUM(BlueprintType)
namespace EFortBounceType {
	enum Type {
		Hit,
		Interact,
		EditPlaced,
	};
}

UENUM(BlueprintType)
namespace EFortDayPhase {
	enum Type {
		Morning,
		Day,
		Evening,
		Night,
		NumPhases,
	};
}

UENUM()
enum class EFortDayPhasePrio : uint8
{
	Default = 0,
	DailySummary = 1,
	EFortDayPhasePrio_MAX = 2 UMETA(Hidden)
};

UENUM()
enum class EFortVehicleDecoType : uint8
{
	Unknown                        = 0,
	Flag                           = 1,
	HoodOrnament                   = 2,
	Wings                          = 3,
	EFortVehicleDecoType_MAX       = 4 UMETA(Hidden),
};

UENUM()
enum class EHotspotTypeConfigMode : uint8
{
	AlwaysAdd = 0,
	WhenNotDefined = 1,
	WhenNotValid = 2,
	EHotspotTypeConfigMode_MAX = 3 UMETA(Hidden)
};

UENUM()
enum class EFortHotSpotDirection : uint8
{
	PositiveX = 0,
	NegativeX = 1,
	PositiveY = 2,
	NegativeY = 3,
	PositiveZ = 4,
	NegativeZ = 5,
	Any = 6,
	EFortHotSpotDirection_MAX = 7 UMETA(Hidden)
};

UENUM(BlueprintType)
enum EBuildingAnim {
	EBA_None,
	EBA_Building,
	EBA_Breaking,
	EBA_Destruction,
	EBA_Placement,
	EBA_DynamicLOD,
	EBA_DynamicShrink,
	EBA_MAX UMETA(Hidden),
};

UENUM(BlueprintType)
enum EBuildingAttachmentSlot {
	SLOT_Floor,
	SLOT_Wall,
	SLOT_Ceiling,
	SLOT_None,
	SLOT_MAX UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortDamageVisualsState : uint8 {
	UnDamaged,
	DamagedAndAnimating,
	DamagedAndStatic,
};

UENUM(BlueprintType)
enum class ELootQuotaLevel : uint8
{
	Unlimited = 0,
	Level1 = 1,
	Level2 = 2,
	Level3 = 3,
	Level4 = 4,
	Level5 = 5,
	Level6 = 6,
	Level7 = 7,
	Level8 = 8,
	Level9 = 9,
	Level10 = 10,
	Level11 = 11,
	Level12 = 12,
	Level13 = 13,
	Level14 = 14,
	Level15 = 15,
	Level16 = 16,
	Level17 = 17,
	NumLevels = 18,
	ELootQuotaLevel_MAX = 19 UMETA(Hidden)
};

UENUM(BlueprintType)
enum EBuildingReplacementType {
	BRT_None,
	BRT_Edited,
	BRT_Upgrade,
	BRT_MAX UMETA(Hidden),
};

UENUM()
enum class EBuildingNavObstacleType : uint8
{
	UnwalkableAll = 0,
	UnwalkableHuskOnly = 1,
	SmashWhenLowHeight = 2,
	SmashOnlyLowHeight = 3,
	SmashSmasherOnly = 4,
	SmashAll = 5,
	EBuildingNavObstacleType_MAX = 6 UMETA(Hidden),
};

UENUM()
enum class EFortAbilityCostSource : uint8
{
	Stamina = 1,
	Durability = 2,
	AmmoMagazine = 3,
	AmmoPrimary = 4,
	Item = 5,
	EFortAbilityCostSource_MAX = 0 UMETA(Hidden, DisplayName = "Default")
};

UENUM(BlueprintType)
enum class EFortGameplayAbilityMontageSectionToPlay : uint8 {
	FirstSection,
	RandomSection,
	TestedRandomSection,
};

UENUM(BlueprintType)
enum class EJumpBoostPackState : uint8 {
	Idle,
	Boost,
	Hovering,
	Falling,
	None,
};

UENUM(BlueprintType)
enum class EFortGameplayCueSourceCondition : uint8 {
	AnySource,
	LocalPlayerSource,
	NonLocalPlayerSource,
};

UENUM(BlueprintType)
namespace EFortGameplayState {
	enum Type {
		NormalGameplay,
		WaitingToStart,
		EndOfZone,
		EnteringZone,
		LeavingZone,
		Invalid,
	};
}

UENUM(BlueprintType)
enum class EFortCheatMissionGenType : uint8 {
	NewGeneration,
	OldGeneration,
	Max_None,
};


UENUM(BlueprintType)
enum class EServerManifestOutputFormat : uint8 {
	FlatFile,
	Json,
	HTTP,
};

UENUM(BlueprintType)
enum class EFortGameplayCueAttachType : uint8 {
	AttachToTarget,
	DoNotAttach,
};


UENUM(BlueprintType)
enum class EMedicPackState : uint8 {
	Idle,
	Active,
	None,
};

UENUM()
enum class EFortTargetSelectionFilter : uint8
{
	Damageable = 1,
	Everything = 2,
	Pawns = 3,
	Buildings = 4,
	Walls = 5,
	Traps = 6,
	Players = 7,
	AIPawns = 8,
	Instigator = 9,
	WeakSpots = 10,
	World = 11,
	Max = 0 UMETA(Hidden, DisplayName = "Default")
};

UENUM()
enum class EFortTargetSelectionShape : uint8
{
	Sphere = 0,
	Cone = 1,
	Box = 2,
	Capsule = 3,
	Line = 4,
	Cylinder = 5,
	Custom = 6,
	CustomOnSource = 7,
	EFortTargetSelectionShape_MAX = 8 UMETA(Hidden)
};

UENUM()
enum class EFortTargetSelectionTestType : uint8
{
	Overlap = 0,
	Swept = 1,
	Ballistic = 2,
	EFortTargetSelectionTestType_MAX = 3 UMETA(Hidden),
};

UENUM()
enum class EFortAbilityTargetSelectionUsage : uint8
{
	BothTargetingAndCanHit = 1,
	OnlyTargeting = 2,
	OnlyCanHit = 3,
	EFortAbilityTargetSelectionUsage_MAX = 0 UMETA(Hidden, DisplayName = "Default")
};

UENUM()
enum class EFortGameplayAbilityActivation : uint8
{
	Passive = 1,
	Triggered = 2,
	Active = 3,
	EFortGameplayAbilityActivation_MAX = 0 UMETA(Hidden, DisplayName = "Default"),
};

UENUM()
enum class EFortAILODLevel : uint8
{
	Invalid = 0,
	Lowest = 1,
	Lower = 2,
	BelowNormal = 3,
	Normal = 4,
	AboveNormal = 5,
	MAX = 6 UMETA(Hidden)
};

UENUM()
enum class EFortAIWeaponUsage : uint8
{
	NoWeaponUsage = 0,
	UsesRangedWeapon = 1,
	UsesMeleeWeapon = 2,
	EFortAIWeaponUsage_MAX = 3 UMETA(Hidden)
};

UENUM()
enum class EFortWeaponOverheatState : uint8
{
	None = 0,
	Heating = 1,
	Cooling = 2,
	Overheated = 3,
	EFortWeaponOverheatState_MAX = 4 UMETA(Hidden)
};


UENUM()
enum class ECameraOrigin : uint8
{
	ViewTargetTransform = 0,
	BoneTransform = 1,
	ECameraOrigin_MAX = 2 UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FFortBounceData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float StartTime;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float BounceValue;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float Radius;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor DeformationVector;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FLinearColor DeformationCenter;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortBounceType::Type> BounceType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bLocalInstigator;
};

UENUM(BlueprintType)
enum class EMusicTrackPlayback : uint8 {
	Disabled,
	Enabled,
};

UENUM(BlueprintType)
namespace EFortUIScoreType {
	enum Type {
		Combat,
		Building,
		Utility,
		Badges,
		Bonus,
		Total,
		Max_None,
	};
}

UENUM(BlueprintType)
namespace EFortCompare {
	enum Type {
		EFC_LessThan,
		EFC_LessThanOrEqual,
		EFC_GreaterThan,
		EFC_GreaterThanOrEqual,
		EFC_Equals,
		EFC_MAX UMETA(Hidden),
	};
	
}
UENUM(BlueprintType)
namespace EFortEventConditionType {
	enum Type {
		EFEC_StatCompare,
		EFEC_CanCraft,
		EFEC_MAX UMETA(Hidden),
	};
}


UENUM(BlueprintType)
namespace EFortEventRepeat {
	enum Type {
		EFER_Inactive,
		EFER_Always,
		EFER_OncePerPlayer,
		EFER_OncePerCampaign,
		EFER_OncePerMap,
		EFER_MAX UMETA(Hidden),
	};
}

UENUM(BlueprintType)
enum class EFortNotificationType : uint8 {
	Default,
	Power,
	HealthWarning,
	Error,
	GiftSent,
	VoiceChannel,
	Max,
};

UENUM(BlueprintType)
enum class EFortNotificationPriority : uint8 {
	Vote,
	Friend,
	BoostedXP,
	TwitchHigh,
	GeneralSendNotification,
	TwitchLow = 0xA,
	Max,
};


USTRUCT()
struct FORTNITEGAME_API FFortBaseWeaponStats : public FTableRowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    int BaseLevel;

    UPROPERTY(EditAnywhere)
    FName NamedWeightRow;

    UPROPERTY(EditAnywhere)
    float DmgPB;

    UPROPERTY(EditAnywhere)
    float DmgMid;

    UPROPERTY(EditAnywhere)
    float DmgLong;

    UPROPERTY(EditAnywhere)
    float DmgMaxRange;

    UPROPERTY(EditAnywhere)
    float EnvDmgPB;

    UPROPERTY(EditAnywhere)
    float EnvDmgMid;

    UPROPERTY(EditAnywhere)
    float EnvDmgLong;

    UPROPERTY(EditAnywhere)
    float EnvDmgMaxRange;

    UPROPERTY(EditAnywhere)
    float ImpactDmgPB;

    UPROPERTY(EditAnywhere)
    float ImpactDmgMid;

    UPROPERTY(EditAnywhere)
    float ImpactDmgLong;

    UPROPERTY(EditAnywhere)
    float ImpactDmgMaxRange;

    UPROPERTY(EditAnywhere)
    bool bForceControl;

    UPROPERTY(EditAnywhere)
    float RngPB;

    UPROPERTY(EditAnywhere)
    float RngMid;

    UPROPERTY(EditAnywhere)
    float RngLong;

    UPROPERTY(EditAnywhere)
    float RngMax;

    UPROPERTY(EditAnywhere)
    UCurveTable* DmgScaleTable;

    UPROPERTY(EditAnywhere)
    FName DmgScaleTableRow;

    UPROPERTY(EditAnywhere)
    float DmgScale;

    UPROPERTY(EditAnywhere)
    UCurveTable* EnvDmgScaleTable;

    UPROPERTY(EditAnywhere)
    FName EnvDmgScaleTableRow;

    UPROPERTY(EditAnywhere)
    float EnvDmgScale;

    UPROPERTY(EditAnywhere)
    UCurveTable* ImpactDmgScaleTable;

    UPROPERTY(EditAnywhere)
    FName ImpactDmgScaleTableRow;

    UPROPERTY(EditAnywhere)
    float ImpactDmgScale;

    UPROPERTY(EditAnywhere)
    FName SurfaceRatioRowName;

    UPROPERTY(EditAnywhere)
    float DamageZone_Light;

    UPROPERTY(EditAnywhere)
    float DamageZone_Normal;

    UPROPERTY(EditAnywhere)
    float DamageZone_Critical;

    UPROPERTY(EditAnywhere)
    float DamageZone_Vulnerability;

    UPROPERTY(EditAnywhere)
    float KnockbackMagnitude;

    UPROPERTY(EditAnywhere)
    float MidRangeKnockbackMagnitude;

    UPROPERTY(EditAnywhere)
    float LongRangeKnockbackMagnitude;

    UPROPERTY(EditAnywhere)
    float KnockbackZAngle;

    UPROPERTY(EditAnywhere)
    float StunTime;

    UPROPERTY(EditAnywhere)
    float StunScale;

    UPROPERTY(EditAnywhere)
    UDataTable* Durability;

    UPROPERTY(EditAnywhere)
    FName DurabilityRowName;

    UPROPERTY(EditAnywhere)
    float DurabilityScale;

    UPROPERTY(EditAnywhere)
    float DurabilityPerUse;

    UPROPERTY(EditAnywhere)
    float DiceCritChance;

    UPROPERTY(EditAnywhere)
    float DiceCritDamageMultiplier;

    UPROPERTY(EditAnywhere)
    float ReloadTime;

    UPROPERTY(EditAnywhere)
    float ReloadScale;

    UPROPERTY(EditAnywhere)
    EFortWeaponReloadType ReloadType;

    UPROPERTY(EditAnywhere)
    bool bAllowReloadInterrupt;

    UPROPERTY(EditAnywhere)
    bool bReloadInterruptIsImmediate;

    UPROPERTY(EditAnywhere)
    int NumIndividualBulletsToReload;

    UPROPERTY(EditAnywhere)
    int ClipSize;

    UPROPERTY(EditAnywhere)
    float ClipScale;

    UPROPERTY(EditAnywhere)
    int InitialClips;

    UPROPERTY(EditAnywhere)
    int CartridgePerFire;

    UPROPERTY(EditAnywhere)
    int AmmoCostPerFire;

    UPROPERTY(EditAnywhere)
    int MaxAmmoCostPerFire;

    UPROPERTY(EditAnywhere)
    float MinChargeTime;

    UPROPERTY(EditAnywhere)
    float MaxChargeTime;

    UPROPERTY(EditAnywhere)
    float ChargeDownTime;

    UPROPERTY(EditAnywhere)
    float MinChargeDamageMultiplier;

    UPROPERTY(EditAnywhere)
    float MaxChargeDamageMultiplier;

    UPROPERTY(EditAnywhere)
    float EquipAnimRate;

    UPROPERTY(EditAnywhere)
    float QuickBarSlotCooldownDuration;
};

USTRUCT(BlueprintType)
struct FFortRangedWeaponStats : public FFortBaseWeaponStats {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float Spread;

    UPROPERTY(EditAnywhere)
    float SpreadDownsights;

    UPROPERTY(EditAnywhere)
    float StandingStillSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float AthenaCrouchingSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float AthenaJumpingFallingSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float AthenaSprintingSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float MinSpeedForSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float MaxSpeedForSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float SpreadDownsightsAdditionalCooldownTime;

    UPROPERTY(EditAnywhere)
    float HeatX1;

    UPROPERTY(EditAnywhere)
    float HeatY1;

    UPROPERTY(EditAnywhere)
    float HeatX2;

    UPROPERTY(EditAnywhere)
    float HeatY2;

    UPROPERTY(EditAnywhere)
    float HeatX3;

    UPROPERTY(EditAnywhere)
    float HeatY3;

    UPROPERTY(EditAnywhere)
    float HeatXScale;

    UPROPERTY(EditAnywhere)
    float HeatYScale;

    UPROPERTY(EditAnywhere)
    float CoolX1;

    UPROPERTY(EditAnywhere)
    float CoolY1;

    UPROPERTY(EditAnywhere)
    float CoolX2;

    UPROPERTY(EditAnywhere)
    float CoolY2;

    UPROPERTY(EditAnywhere)
    float CoolX3;

    UPROPERTY(EditAnywhere)
    float CoolY3;

    UPROPERTY(EditAnywhere)
    float CoolXScale;

    UPROPERTY(EditAnywhere)
    float CoolYScale;

    UPROPERTY(EditAnywhere)
    float PerfectAimCooldown;

    UPROPERTY(EditAnywhere)
    int BulletsPerCartridge;

    UPROPERTY(EditAnywhere)
    float FiringRate;

    UPROPERTY(EditAnywhere)
    float ROFScale;

    UPROPERTY(EditAnywhere)
    float BurstFiringRate;

    UPROPERTY(EditAnywhere)
    float FiringRateDownsightsMultiplier;

    UPROPERTY(EditAnywhere)
    float AutofireAcquisitionDelay;

    UPROPERTY(EditAnywhere)
    float AutofireCooldown;

    UPROPERTY(EditAnywhere)
    float RecoilVert;

    UPROPERTY(EditAnywhere)
    float RecoilVertScale;

    UPROPERTY(EditAnywhere)
    float RecoilVertScaleGamepad;

    UPROPERTY(EditAnywhere)
    float VertRecoilDownChance;

    UPROPERTY(EditAnywhere)
    float RecoilHoriz;

    UPROPERTY(EditAnywhere)
    float RecoilHorizScale;

    UPROPERTY(EditAnywhere)
    float RecoilHorizScaleGamepad;

    UPROPERTY(EditAnywhere)
    float RecoilInterpSpeed;

    UPROPERTY(EditAnywhere)
    float RecoilRecoveryInterpSpeed;

    UPROPERTY(EditAnywhere)
    float RecoilRecoveryDelay;

    UPROPERTY(EditAnywhere)
    float RecoilRecoveryFraction;

    UPROPERTY(EditAnywhere)
    float RecoilDownsightsMultiplier;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilMagnitudeMin;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilMagnitudeMax;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilMagnitudeScale;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilAngleMin;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilAngleMax;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilRollMagnitudeMin;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilRollMagnitudeMax;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilInterpSpeed;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilRecoveryInterpSpeed;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilDownsightsMultiplier;

    UPROPERTY(EditAnywhere)
    float AthenaRecoilHipFireMultiplier;

    UPROPERTY(EditAnywhere)
    float AthenaAimAssistRange;

    UPROPERTY(EditAnywhere)
    float ADSTransitionInTime;

    UPROPERTY(EditAnywhere)
    float ADSTransitionOutTime;

    UPROPERTY(EditAnywhere)
    int MaxSpareAmmo;

    UPROPERTY(EditAnywhere)
    int BulletsPerTracer;

    UPROPERTY(EditAnywhere)
    float AIDelayBeforeFiringMin;

    UPROPERTY(EditAnywhere)
    float AIDelayBeforeFiringMax;

    UPROPERTY(EditAnywhere)
    float AIFireDurationMin;

    UPROPERTY(EditAnywhere)
    float AIFireDurationMax;

    UPROPERTY(EditAnywhere)
    float AIMinSpreadDuration;

    UPROPERTY(EditAnywhere)
    float AIMaxSpreadDuration;

    UPROPERTY(EditAnywhere)
    float AIDurationSpreadMultiplier;

    UPROPERTY(EditAnywhere)
    float AIAdditionalSpreadForTargetMovingLaterally;

    UPROPERTY(EditAnywhere)
    float AIAthenaHearFiringNoiseRange;

    UPROPERTY(EditAnywhere)
    float EQSDensity;

    UPROPERTY(EditAnywhere)
    float MinApproachRange;

    UPROPERTY(EditAnywhere)
    float MinActualRange;

    UPROPERTY(EditAnywhere)
    float MinPreferredRange;

    UPROPERTY(EditAnywhere)
    float MinPreferredRangeEQS;

    UPROPERTY(EditAnywhere)
    float MaxPreferredRangeEQS;

    UPROPERTY(EditAnywhere)
    float MaxPreferredRange;

    UPROPERTY(EditAnywhere)
    float MaxActualRange;

    UPROPERTY(EditAnywhere)
    float MaxApproachRange;

    UPROPERTY(EditAnywhere)
    float SweepRadius;

    UPROPERTY(EditAnywhere)
    float AutoReloadDelayOverride;

    UPROPERTY(EditAnywhere)
    float OverheatingMaxValue;

    UPROPERTY(EditAnywhere)
    float OverheatHeatingValue;

    UPROPERTY(EditAnywhere)
    float OverheatingCoolingValue;

    UPROPERTY(EditAnywhere)
    float HeatingCooldownDelay;

    UPROPERTY(EditAnywhere)
    float OverheatedCooldownDelay;

    UPROPERTY(EditAnywhere)
    float FortHomingTurnSpeedMin;

    UPROPERTY(EditAnywhere)
    float FortHomingTurnSpeedMax;

    UPROPERTY(EditAnywhere)
    float FortHomingTimeUntilMaxTurnSpeed;
};

USTRUCT(BlueprintType)
struct FFortMeleeWeaponStats : public FFortBaseWeaponStats {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(EditAnywhere)
	float RangeVSEnemies;

	UPROPERTY(EditAnywhere)
	float ConeYawAngle;

	UPROPERTY(EditAnywhere)
	float ConePitchAngle;

	UPROPERTY(EditAnywhere)
	float SwingPlaySpeed;

	UPROPERTY(EditAnywhere)
	float SwingTime;

	UPROPERTY(EditAnywhere)
	float BuildingConeAngle;

	UPROPERTY(EditAnywhere)
	float BuildingConeAnglePitch;

	UPROPERTY(EditAnywhere)
	float RangeVSBuildings2D;

	UPROPERTY(EditAnywhere)
	float RangeVSBuildingsZ;

	UPROPERTY(EditAnywhere)
	float RangeVSWeakSpots;
};

USTRUCT(BlueprintType)
struct FBuildingNavObstacle
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBox LocalBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EBuildingNavObstacleType ObstacleType;
};

USTRUCT(BlueprintType)
struct FDamageDistanceTagEval
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DistanceLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag DistanceTag;
};

USTRUCT(BlueprintType)
struct FEditorOnlyBuildingInstanceMaterialParameters
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<struct FScalarParameterValue> ScalarParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<struct FVectorParameterValue> VectorParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<struct FTextureParameterValue> TextureParams;
};

USTRUCT(BlueprintType)
struct FFortConnectionData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ABuildingSMActor* ConnectedActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGuid ConnectedActorGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName MySocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName TheirSocketName;
};

USTRUCT(BlueprintType)
struct FFortConnectivityComponentData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<struct FFortConnectionData> Connections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsPowered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsProvidingPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowConnections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowsPowerToPassThrough;
};

USTRUCT(BlueprintType)
struct FQuantizedBuildingAttribute
{
	GENERATED_BODY()

public:
	float Value;
};

USTRUCT(BlueprintType)
struct FBuildingActorMinimalReplicationProxy
{
	GENERATED_BODY()

public:
	struct FQuantizedBuildingAttribute BuildTime;
	struct FQuantizedBuildingAttribute RepairTime;
	int16 Health;
	int16 MaxHealth;
};

USTRUCT(BlueprintType)
struct FChosenQuotaInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int LootTier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LootTierKey;
};

USTRUCT(BlueprintType)
struct FBuildingActorHotSpotDirection
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAIHotSpotConfig* HotSpotConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		struct FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMirrorX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMirrorY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EFortHotSpotDirection Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EHotspotTypeConfigMode TypeConfigUsage;
};

USTRUCT(BlueprintType)
struct FConnectivityCube
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FRandomDayphaseFX
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UParticleSystem* ParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class UParticleSystem*> AltParticleSystems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TEnumAsByte<EFortDayPhase::Type>> RequiredDayphases;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ChanceToSpawnFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EDetailMode> DetailMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxDrawDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
		bool bRandomSelectionAlreadyHappened;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
		class UParticleSystemComponent* SpawnedComponent;
};

USTRUCT(BlueprintType)
struct FAnimatingMaterialPair
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInterface* Original;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInterface* Override;

};

USTRUCT(BlueprintType)
struct FFortCameraInstanceEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class UFortCameraMode> CameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AActor* ViewTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UFortCameraMode* Camera;

};

USTRUCT(BlueprintType)
struct FFortHighlightColors
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	struct FLinearColor OutlineColor;

	UPROPERTY(EditAnywhere)
	struct FLinearColor SceneModulationColor1;

	UPROPERTY(EditAnywhere)
	struct FLinearColor SceneModulationColor2;
};

USTRUCT(BlueprintType)
struct FFortHighlightColorsContainer
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	struct FFortHighlightColors ValidHighlight;

	UPROPERTY(EditAnywhere)
	struct FFortHighlightColors InvalidHighlight;
};

USTRUCT(BlueprintType)
struct FFortReplicatedStatMapping
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EStatCategory> StatCategory;

	UPROPERTY(EditAnywhere)
	FText DisplayName;
};

USTRUCT(BlueprintType)
struct FActiveFortCamera
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UFortCameraMode* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AActor* ViewTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TransitionAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TransitionUpdateRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BlendWeight;

};

USTRUCT(BlueprintType)
struct FPenetrationAvoidanceFeeler
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FRotator AdjustmentRot;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float WorldWeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float PawnWeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Extent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int TraceInterval;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int FramesUntilNextTrace;
};

USTRUCT(BlueprintType)
struct FInterpOffsetData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector ViewOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector LargeBodyTypeAddtnlOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float PitchAngle;
};

USTRUCT(BlueprintType)
struct FInterpOffset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FInterpOffsetData> SamplePoints;
};


USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortMultiSizeBrush {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush Brush_XXS;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush Brush_XS;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush Brush_S;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush Brush_M;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush Brush_L;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FSlateBrush Brush_XL;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortColorPalette {
	GENERATED_BODY()
public:
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
};

USTRUCT(BlueprintType)
struct FFortCameraModeOverride
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<UFortCameraMode> OriginalClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<UFortCameraMode> ClassOverride;
};

USTRUCT(BlueprintType)
struct FFortCameraPrototype
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName PrototypeName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString PrototypeDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FFortCameraModeOverride> ModeOverrides;
};