// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortGlobals.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FLoginFailureLogSubmitOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSubmitLogs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LogTailKb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LogSubmitChance;
/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ELoginResult> DoNotUploadReasons;*/
};

USTRUCT(BlueprintType)
struct FPurchaseFailureLogSubmitOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bSubmitLogs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 LogTailKb;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float LogSubmitChance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FString> DoNotUploadReasons;
};

USTRUCT(BlueprintType)
struct FPartyFailureLogSubmitReason
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reason;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SubReason;
};


USTRUCT(BlueprintType)
struct FLogoutLogSubmitOptions
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bSubmitLogs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bSubmitLogsDuringLogin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 LogTailKb;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float LogSubmitChance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FString> DoNotUploadReasons;
};

USTRUCT(BlueprintType)
struct FPartyFailureLogSubmit
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSubmitLogs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LogTailKb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LogSubmitChance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPartyFailureLogSubmitReason> Reasons;
};




UCLASS(Config=FortGlobals, Transient, Blueprintable, hideCategories=(Input))
class FORTNITEGAME_API UFortGlobals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString LobbyMap;

	UPROPERTY(Config)
	int32 MinTheaterListRefreshDelay;

	UPROPERTY(Config)
	int32 MaxTheaterListRefreshDelay;

	UPROPERTY(Config)
	float MinCullObjectSize;

	UPROPERTY(Config)
	float MinCullDistance;

	UPROPERTY(Config)
	float MaxCullObjectSize;

	UPROPERTY(Config)
	float MaxCullDistance;

	UPROPERTY(Config)
	float MinRespawnHeightForEnvironmentDeath;

	UPROPERTY(Config)
	float MaxRespawnInAirHeight;

	UPROPERTY(Config)
	bool bEnablePlayerTriggeredRespawn;

	UPROPERTY(Config)
	bool bEnableNewCustomizationPanel;

	UPROPERTY(Config)
	bool bEnableInfluenceMap;

	UPROPERTY(Config)
	bool bEnableAIDespawning;

	UPROPERTY(Config)
	bool bEnableDBNO;

	UPROPERTY(Config)
	bool bEnableIronCity;

	UPROPERTY(Config)
	bool bEnableForceBuildingActorRecordUpdates;

	UPROPERTY(Config)
	TArray<FName> IronCityWargameTagList;

	UPROPERTY(Config)
	bool bEnableIronCityCoast;

	UPROPERTY(Config)
	bool bEnableHestia;

	UPROPERTY(Config)
	bool bEnableIronCityAutoAmplifierPlacement;

	UPROPERTY(Config)
	bool bEnableWargameDebug;

	UPROPERTY(Config)
	bool bEnableEnduranceDebug;

	UPROPERTY(Config)
	bool bEnableMilestoneMode;

	UPROPERTY(Config)
	int32 MaxAssetsToPreload;

	UPROPERTY(Config)
	bool bOnlyPreloadCity;

	UPROPERTY(Config)
	bool bEnableInWorldScoreNumbers;

	UPROPERTY(Config)
	bool bMustUseToggleJetpackExecute;

	UPROPERTY(Config)
	bool bEnableNewRewardFlow;

	UPROPERTY(Config)
	bool bEnableWIFE;

	UPROPERTY(Config)
	bool bEnableFrontendCrafting;

	UPROPERTY(Config)
	bool bEnableFrontendStorage;

	UPROPERTY(Config)
	bool bEnableLazyASC;

	UPROPERTY(Config)
	bool bEnableFriendCodes;

	UPROPERTY(Config)
	bool bEnableCreativeMode;

	UPROPERTY(Config)
	bool bEnableCreativeModeLimitedAccess;

	UPROPERTY(Config)
	bool bEnableCreativeModeLimitedAccessForFounders;

	UPROPERTY(Config)
	float FlyVerificationInterval;

	UPROPERTY(Config)
	FString CreativeModeLimitedAccessEndTime;

	UPROPERTY(Config)
	bool bEnableCreativeModeTutorials;

	UPROPERTY(Config)
	float CreativeTutorialSkydivingDelay;

	UPROPERTY(Config)
	float CreativeReturnToHubTutorialDelay;

	UPROPERTY(Config)
	FLoginFailureLogSubmitOptions LoginFailureOptions;

	UPROPERTY(Config)
	FLogoutLogSubmitOptions LogoutFailureOptions;

	UPROPERTY(Config)
	FPurchaseFailureLogSubmitOptions RealMoneyPurchaseFailureOptions;

	UPROPERTY(Config)
	bool bSubmitReturnToMenuErrorLogs;

	UPROPERTY(Config)
	int32 ReturnToMenuErrorLogTailKb;

	UPROPERTY(Config)
	float ReturnToMenuErrorLogSubmitChance;

	UPROPERTY(Config)
	FPartyFailureLogSubmit PartyJoinFailureLogSubmit;

	UPROPERTY(Config)
	bool bShowSkillTreeMovies;

	UPROPERTY(Config)
	bool bShowMissionResultsMovies;

	UPROPERTY(Config)
	bool bDisablePlayerTeleportDuringMissionResults;

	UPROPERTY(Config)
	bool bDisableParticleEffectsDuringMissionResults;

	UPROPERTY(Config)
	bool bFlushGPUWhenPlayerIsTeleportedAtEndOfZone;

	UPROPERTY(Config)
	bool bStreamOutTextureDataWhenPlayerIsTeleportedAtEndOfZone;

	UPROPERTY(Config)
	bool bTwitchEnabled;

	UPROPERTY(Config)
	bool bTwitchAllowDisplayViewernames;

	UPROPERTY(Config)
	int32 MaxTwitchViewerNamesToCache;

	UPROPERTY(Config)
	int32 TwitchViewerNameExpirationMinutes;

	UPROPERTY(Config)
	float MinTwitchHeartbeatInterval;

	UPROPERTY(Config)
	float TwitchAccountInformationRefreshInterval;

	UPROPERTY(Config)
	bool bAllowLogout;

	UPROPERTY(Config)
	bool bAllowQuit;

	UPROPERTY(Config)
	bool bHasWorldMap;

	UPROPERTY(Config)
	float PlayerJoinServerTimeoutSeconds;

	UPROPERTY(Config)
	float PlayerUnregistrationFailsafeTimer;

	UPROPERTY(Config)
	float PollForDedicatedServerReadyToShutdownInterval;

	UPROPERTY(Config)
	bool bUploadAthenaStats;

	UPROPERTY(Config)
	bool bUploadAthenaStatsV2;

	UPROPERTY(Config)
	bool bDisableTimePlayedStat;

	UPROPERTY(Config)
	bool bAthenaStatsFrontendEnabled;

	UPROPERTY(Config)
	bool bAthenaLeaderboardFrontEndEnabled;

	UPROPERTY(Config)
	bool bAthenaSquadQuickChatEnabled;

	UPROPERTY(Config)
	float AthenaQuickChatRangeForNonSquadTeamMembers;

	UPROPERTY(Config)
	bool bGlobalLeaderboardsFrontEndEnabled;

	UPROPERTY(Config)
	int32 TimeBetweenLeaderboardRequestsMinutes;

	UPROPERTY(Config)
	bool bFirstShotAccuracyDisabled;

	UPROPERTY(Config)
	bool bAllowProjectileRethrow;

	UPROPERTY(Config)
	bool bAthenaUsesSimCollision;

	UPROPERTY(Config)
	bool bAthenaSimVehicles;

	UPROPERTY(Config)
	bool bAthenaSubstepping;

	UPROPERTY(Config)
	bool bCampaignSubstepping;

	UPROPERTY(Config)
	bool bCampaignUsesSimCollision;

	UPROPERTY(Config)
	bool bCampaignSimVehicles;

	UPROPERTY(Config)
	float MaximumCharacterVelocity;

	UPROPERTY(Transient)
	TArray<UObject*> AthenaReferencedObjects;

	UPROPERTY(Transient)
	int32 NumOutstandingAthenaAsyncRequests;

	UPROPERTY(Transient)
	int32 TotalAthenaAsyncRequests;

	UPROPERTY(Transient)
	TSoftClassPtr<AActor> AthenaAlwaysLoadedContentHack;
	
};

