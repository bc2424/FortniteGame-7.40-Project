#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "FortniteGame.h"
#include "FortInitializationInterface.h"
#include "FortMutatorOwner.h"
#include "MinigamePlayer.h"
#include "MinigamePlayerBucket.h"
#include "MinigamePlayers.h"
#include "FortPlaylistAthena.h"
#include "Templates/SubclassOf.h"
#include "FortMinigame.generated.h"

class AActor;
class AController;
class AFortGameplayMutator;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortPlayerStateZone;
class AFortVolume;
class APawn;
class APlayerState;
class ASolarisPrototype;
class UFortCreativeCreatureManagerComponent;
class UFortMinigameLogicComponent;
class UFortMinigamePlayerStartComponent;
class UFortMinigameStatFilter;
class UObject;
class USceneComponent;

USTRUCT(BlueprintType)
struct FFortMinigameStatQuery {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFortMinigameStatFilter> Stat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFortMinigameStatScope Scope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAnyMatch: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFortMinigameStatOperation Operation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bStaticCount: 1;
};

USTRUCT(BlueprintType)
struct FMinigameEndCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFortMinigameStatQuery StatQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMinigameTeamListType TeamListType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> TeamList;
};

USTRUCT(BlueprintType)
struct FFortMinigameStat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFortMinigameStatFilter> Filter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Count;
};

USTRUCT(BlueprintType)
struct FFortMinigameGroupStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFortMinigameStat> Stats;
};

USTRUCT(BlueprintType)
struct FFortMinigamePlayerStats : public FFortMinigameGroupStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUniqueNetIdRepl Player;
};
USTRUCT(BlueprintType)
struct FFortMinigamePlayerBucketStats : public FFortMinigameGroupStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BucketIndex;
};

USTRUCT(BlueprintType)
struct FFortMinigameStatCollection {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFortMinigameGroupStats GroupStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFortMinigamePlayerStats> PlayerStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFortMinigamePlayerBucketStats> PlayerBucketStats;
};

USTRUCT(BlueprintType)
struct FMinigameTeam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TeamIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxInitTeamSize;
};


USTRUCT(BlueprintType)
struct FFortMinigameTimes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SetupTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarmupTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResetTime;
};


USTRUCT(BlueprintType)
struct FMinigameScoreboardValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFortMinigameStatFilter> StatFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHighlight;
};

USTRUCT(BlueprintType)
struct FMingiameScoreboardRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMinigameScoreboardValue> Values;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WinCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHighlight;
};

USTRUCT(BlueprintType)
struct FMinigameScoreboardPlayerRow : public FMingiameScoreboardRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFortPlayerState* PlayerState;
};

USTRUCT(BlueprintType)
struct FMinigameStatRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText PlayerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FText> PlayerStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsTeamRow;
};

USTRUCT(BlueprintType)
struct FMinigameScoreboardBucketRow : public FMingiameScoreboardRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Standing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BucketIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMinigameScoreboardPlayerRow> PlayerRows;
};

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChanged, EFortMinigameState, MinigameState);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameHideHUD, bool, bHideHUD);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleMinigameDelegate);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerChanged, FUniqueNetIdRepl, UniqueNetId, bool, bIsLocalPlayer);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerJoinInProgress, APawn*, Pawn);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerPawnEvent, AFortPlayerPawn*, PlayerPawn);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUIExtensionsChanged, AFortMinigame*, Minigame);

UCLASS(Abstract, Blueprintable)
class FORTNITEGAME_API AFortMinigame : public AInfo, public IFortMutatorOwner, public IFortInitializationInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<FUniqueNetIdRepl> PendingPlayers;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnStateChanged StateChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinigameHideHUD MinigameHideHUDDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleMinigameDelegate StatChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerChanged PlayerAddedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerChanged PlayerRemovedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerJoinInProgress OnPlayerJoinInProgress;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleMinigameDelegate MinigameStartedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleMinigameDelegate MinigameEndedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerPawnEvent OnPawnTeleportedForMinigame;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUIExtensionsChanged OnUIExtensionsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlaylistUIExtension> UIExtensions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=DoRep_UIExtensionTags, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer UIExtensionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float TimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 CurrentRound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 TotalRounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FMinigamePlayers PlayerArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FMinigamePlayers SpectatingPlayerArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FMinigameEndCondition> EndConditionArray;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 AutoStartDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EFortMinigamePlayerSpawnLocationSetting SpawnLocationSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EFortMinigamePostGameSpawnLocationSetting PostGameSpawnLocationSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float WarmupDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float PostGameResetDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float GameWinnerDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float GameScoreDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float RoundWinnerDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float RoundScoreDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bTimerCountsDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMinigameTeam> TeamArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFortMinigameStatQuery> BaseEndConditionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UFortMinigameStatFilter>> TrackedStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UFortMinigameStatFilter>> ScoreboardStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_StatsChanged, meta=(AllowPrivateAccess=true))
    FFortMinigameStatCollection RoundStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_StatsChanged, meta=(AllowPrivateAccess=true))
    FFortMinigameStatCollection GameStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentState, meta=(AllowPrivateAccess=true))
    EFortMinigameState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EFortMinigameState PreviousState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFortMinigameStatFilter> CompletionTimeStatFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFortMinigameStatFilter> PlayerDeathsStatFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 MaxLivesForPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFortTeam::Type> TeamToSwapToWhenOutOfSpawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AutoEndTeamThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentState, meta=(AllowPrivateAccess=true))
    FFortMinigameTimes ServerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFortMinigameTimes CachedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bStopwatchMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastRoundDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFortMinigameLogicComponent*> MinigameComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFortMinigamePlayerStartComponent*> PlayerStartComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFortCreativeCreatureManagerComponent* CreatureManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AFortVolume* Volume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bSortScoreboardEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bTeamMinigame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASolarisPrototype* LivePlayerScript;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumTeams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bAllowJoinInProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AFortPlayerState* MinigameStarter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TeamRotationSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 TeamRotationCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EMinigameFullscreenMapWidgetType MinigameMapWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MinigameStartCameraBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ClientMinigameStartedText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MinigameEndCameraBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ClientMinigameEndedText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FPlaylistUIExtension> AllowedUIExtensions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 WinningTeamIndex;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 NumMinigameComponentsServer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bVolumeNavigationHasBuilt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> RoundWinHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMinigamePlayerBucket> PlayerBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer OldUIExtensionTags;
    
public:
    AFortMinigame();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasInProgress() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void UnregisterVolumeAsNavigationObserver(USceneComponent* RegisteredComponent);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ToggleAutoRestartMinigame();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintNativeEvent)
    void StartMinigame(AFortPlayerController* InstigatorPC);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldRotateTeams() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupTeams();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SetTeamForPlayer(AFortPlayerState* PlayerState, uint8 NewTeam, bool bTemporary);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetStatForPlayerId(const FUniqueNetIdRepl& InPlayerID, TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetStatForPlayerBucket(int32 BucketIndex, TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetStatForPlayer(const AFortPlayerState* InPlayer, TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetStatForGroup(TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SetPvPTeamForPlayer(AFortPlayerState* PlayerState, int32 Team, bool bTemporary);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetMaxInitTeamSizeForTeam(uint8 TeamIndex, int32 TeamSize);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintNativeEvent)
    void RestartMinigame(AFortPlayerController* InstigatorPC);
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ResetStats();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveMinigamePlayer(AFortPlayerState* PlayerState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveMinigameComponent(UFortMinigameLogicComponent* MinigameComponent);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveMinigameActor(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RemoveEndConditionForTeam(uint8 TeamIndex, const FFortMinigameStatQuery& StatQuery);
    
    UFUNCTION(BlueprintCallable)
    void RemoveEndCondition(const FFortMinigameStatQuery& StatQuery);
    
private:
    UFUNCTION(BlueprintCallable)
    void RegisterVolumeAsNavigationObserver();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RefreshVoiceForPlayers();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RefreshVoiceForPlayer(AFortPlayerState* PlayerState);
    
    UFUNCTION(BlueprintCallable)
    void RecheckInventory(APawn* PlayerPawn);
    
private:
    UFUNCTION(BlueprintCallable)
    void QueueAllAIForDespawn();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PutPlayerIntoStasis(APawn* PlayerPawn);
    
    UFUNCTION(BlueprintCallable)
    void PutPlayerControllerIntoStasis(AFortPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    void PostGameResetPlayers();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OverridePlayerSpawnLocation(APawn* PlayerPawn, AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation, bool& bOutRespawningOnGround);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnVolumeStateChanged(EVolumeState NewState, AFortVolume* ChangedVolume);
    
    UFUNCTION(BlueprintCallable)
    void OnTimeLimitElapsed();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_StatsChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentState();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerPawnPossessedDuringTransition(APawn* PlayerPawn);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerPawnPossessedDuringMinigame(APawn* PlayerPawn);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerPawnDiedDuringMinigame(AFortPlayerPawnAthena* PlayerPawn);
    
    UFUNCTION(BlueprintCallable)
    void OnInGameLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnGamePhaseChanged(EAthenaGamePhase GamePhase);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnClientFinishTeleportingForMinigame(AFortPlayerPawn* InPawn);
    
    UFUNCTION(BlueprintCallable)
    bool OnCheckIfClientIsSafeToRespawn(AFortPlayerControllerAthena* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginSpectating(AFortPlayerStateZone* FPSZ);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void NotifyStatEvent(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    void NativeExitedVolumeEvent(AFortPlayerState* LeftPlayerState);
    
    UFUNCTION(BlueprintCallable)
    void NativeEnteredVolumeEvent(AFortPlayerState* PlayerState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void MoveMinigamePlayerToSpectate(AFortPlayerState* PlayerState);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void K2_RecordPostGameStatsForPlayer(UPARAM(Ref) FMinigamePlayer& PlayerEntry);
    
public:
    UFUNCTION(BlueprintCallable)
    void K2_IsInProgress(EFortMinigameExec& OutExec);
    
    UFUNCTION(BlueprintCallable)
    void K2_HasStarted(EFortMinigameExec& OutExec);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void K2_ExitedVolumeEvent(AFortPlayerState* LeftPlayerState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void K2_EnteredVolumeEvent(AFortPlayerState* PlayerState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWinningPlayerState(const APlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWinningPlayerId(const FUniqueNetIdRepl& PlayerID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTransitioning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPregame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPostGame() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool IsPlayerTeleportingOrRespawningForGameplay(AFortPlayerStateAthena* PlayerToCheck);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerSpectatingMinigame(const AFortPlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerOutOfLives(const AFortPlayerState* InPlayerState) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerLocationBlockedForTeleport(AFortPlayerPawnAthena* PlayerPawn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInOurVolume(AFortPlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInMinigameByNetId(const FUniqueNetIdRepl& UniqueNetId, bool bCheckSpectatingPlayers) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInMinigame(const AFortPlayerState* PlayerState, bool bCheckSpectatingPlayers) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMinigameStarter(AFortPlayerController* PlayerController) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMinigameComponent(UFortMinigameLogicComponent* MinigameComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMinigameActor(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsLocationInsideTerrain(FVector Location, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable)
    bool IsLocationBlockedForTeleport(AFortPlayerState* PlayerState, FVector LocationToCheck, FRotator RotationToCheck);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastRound() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInSetup() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGameWinnerShown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyPlayerSpawnLimited() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool IsAnyEndConditionComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsActorPositionInsideTerrain(AActor* Actor, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable)
    static void HighlightTopStats(UPARAM(Ref) TArray<FMinigameScoreboardBucketRow>& InOutScoreboardRows);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTimeLimit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStarted() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMinigameStarter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleVolumeEditModeChange(bool bInEditMode);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleReplicationComplete(AFortPlayerControllerAthena* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameWarmup();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameEnded();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameComponentRemoved(UFortMinigameLogicComponent* MinigameComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameComponentInPlayChanged(UFortMinigameLogicComponent* MinigameComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameComponentAdded(UFortMinigameLogicComponent* MinigameComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWarmupTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeRemainingUntilAutoStart() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetTeamToSwapToWhenOutOfSpawns(const AFortPlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStatForPlayerId(const FUniqueNetIdRepl& PlayerID, TSubclassOf<UFortMinigameStatFilter> InFilter, bool bGameTotal) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStatForPlayerBucket(int32 BucketIndex, TSubclassOf<UFortMinigameStatFilter> InFilter, bool bGameTotal) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStatForPlayer(const AFortPlayerState* InPlayer, TSubclassOf<UFortMinigameStatFilter> InFilter, bool bGameTotal) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStatForGroup(TSubclassOf<UFortMinigameStatFilter> InFilter, bool bGameTotal) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTagQuery GetStartQueryForPlayer(APlayerState* Player);
    
    UFUNCTION(BlueprintCallable)
    int32 GetStandingsForPlayer(const AFortPlayerState* InPlayerState, TSubclassOf<UFortMinigameStatFilter> InFilter, TArray<FMinigameStatRow>& OutStatRows, int32 RowsReturned);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFortMinigamePlayerSpawnLocationSetting GetSpawnLocationSetting(const AFortPlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetScoreboardRows(TArray<FMinigameScoreboardBucketRow>& OutScoreboardRows, const TArray<TSubclassOf<UFortMinigameStatFilter>>& SortOrder, bool bGameTotal, bool bHighlighting, bool bCountWins) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetScoreboardRowForPlayerBucket(int32 BucketIndex, FMinigameScoreboardBucketRow& OutScoreboardRow, const TArray<TSubclassOf<UFortMinigameStatFilter>>& SortOrder, bool bGameTotal, bool bHighlighting, bool bCountWins) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetScoreboardRowForPlayer(AFortPlayerState* PlayerState, FMinigameScoreboardPlayerRow& OutScoreboardRow, const TArray<TSubclassOf<UFortMinigameStatFilter>>& SortOrder, bool bGameTotal, bool bHighlighting, bool bCountWins) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRuntime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRoundWinner(int32 Round) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRoundBasedGameWinnerName(FText& OutName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPostGameTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPostGameResetDelay() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPlayerStartComponentsByTagQuery(TArray<UFortMinigamePlayerStartComponent*>& OutPlayerStartComponents, const FGameplayTagQuery& TagQuery);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPlayerCount(bool bIncludeSpectators) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetParticipatingPlayers(TArray<AFortPlayerState*>& OutPlayers) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetOrderedMinigameStatsRows(TArray<FMinigameStatRow>& OutStats);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMinigameFullscreenMapWidgetType GetMinigameMapPanelDisplayType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMinigameComponentsByTagQuery(TArray<UFortMinigameLogicComponent*>& OutComponents, const FGameplayTagQuery& TagQuery) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxLivesForPlayer(const AFortPlayerState* PlayerState) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxInitTeamSize(uint8 TeamIndex) const;
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetEndConditionValueForStatIfAny(const uint8 TeamNumber, const TSubclassOf<UFortMinigameStatFilter>& InStat, int32& OutValue);
    
    UFUNCTION(BlueprintCallable)
    bool GetEndConditionForStatIfAny(const uint8 TeamNumber, const TSubclassOf<UFortMinigameStatFilter>& InStat, FMinigameEndCondition& OutEndCondition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCurrentRoundWinnerName(FText& OutName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentRoundWinner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBucketForPlayerState(const APlayerState* PlayerState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBucketForPlayerId(const FUniqueNetIdRepl& PlayerID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAirSpawnLocation(AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText FormatStat(TSubclassOf<UFortMinigameStatFilter> InStat, int32 InValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool EvaluateStatQuery(const FMinigameEndCondition& InEndCondition) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void EndGame(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod);
    
protected:
    UFUNCTION(BlueprintCallable)
    void DoRep_UIExtensionTags();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoAllPlayersHaveSpawnLocation(EFortMinigamePlayerSpawnLocationSetting SpawnLocation) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool DetermineSpawnLocation(AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation, bool& bOutRespawningOnGround);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ClearTeleportForMinigame(AFortPlayerPawn* InPawn);
    
    UFUNCTION(BlueprintCallable)
    void ClearPlayerInventory(AFortPlayerControllerAthena* PlayerController);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* ChoosePlayerStart(AController* Player);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool CheckRemainingLivingPlayersForEndCondition();
    
    UFUNCTION(BlueprintCallable)
    void CheckEndConditionsInternal();
    
    UFUNCTION(BlueprintCallable)
    void CheckEndConditions();
    
    UFUNCTION(BlueprintCallable)
    bool CheckCustomEndConditions();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanPlayerRespawn(const AFortPlayerState* InPlayerState) const;
    
private:
    UFUNCTION(BlueprintCallable)
    void BroadcastStatsChangedDelegate();
    
public:
    UFUNCTION(BlueprintCallable)
    bool AreEnoughPlayersLeftToContinueMatch();
    
    UFUNCTION(BlueprintCallable)
    void AdvanceState();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddStatToPlayerBucket(int32 BucketIndex, TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddStatToPlayer(AFortPlayerState* InPlayer, TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddStatToGroup(TSubclassOf<UFortMinigameStatFilter> InFilter, int32 InValue);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddOrOverrideEndConditionForTeam(uint8 TeamIndex, const FFortMinigameStatQuery& StatQuery);
    
    UFUNCTION(BlueprintCallable)
    void AddOrOverrideEndCondition(const FFortMinigameStatQuery& StatQuery);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddMinigamePlayer(AFortPlayerState* PlayerState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddMinigameComponent(UFortMinigameLogicComponent* MinigameComponent);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddMinigameActor(AActor* Actor);
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void RemoveMutatorFromList(AFortGameplayMutator* Mutator) PURE_VIRTUAL(RemoveMutatorFromList,);
    
    UFUNCTION()
    void GetMutatorsForContextActor(TArray<AFortGameplayMutator*>& OutMutators, const AActor* ContextActor) const PURE_VIRTUAL(GetMutatorsForContextActor,);
    
    UFUNCTION()
    void GetMutatorRelevantPlayers(TArray<APlayerState*>& OutPlayers) const PURE_VIRTUAL(GetMutatorRelevantPlayers,);
    
    UFUNCTION()
    void AddMutatorToList(AFortGameplayMutator* Mutator) PURE_VIRTUAL(AddMutatorToList,);
    
    UFUNCTION()
    void WorldReady() override PURE_VIRTUAL(WorldReady,);
    
    UFUNCTION()
    bool NeedsWorldReady() const override PURE_VIRTUAL(NeedsWorldReady, return false;);
    
    UFUNCTION()
    void MatchStarted() override PURE_VIRTUAL(MatchStarted,);
};

