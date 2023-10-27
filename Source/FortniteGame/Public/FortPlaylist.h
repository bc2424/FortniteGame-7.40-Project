// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "PlaylistUserOptions.h"
#include "FortWorldItemDefinition.h"
#include "GameplayTagContainer.h"
#include "FortGameplayModifierItemDefinition.h"
#include "FortTimeOfDayManager.h"
#include "FortPlaylist.generated.h"


UCLASS()
class UFortSharedAssetList : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<UFortWorldItemDefinition*> SharedItemsToFullyLoad;

    UPROPERTY(EditAnywhere)
    TArray<TSoftObjectPtr<UWorld>> SharedAdditionalLevels;                            
};
UCLASS()
class UFortSharedAssetGroup : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<UFortSharedAssetList*> SharedAssetsToLoad;
};

UCLASS()
class UFortConditionalAssetGroup : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TMap<FString, UFortSharedAssetList*> ConditionalAssetsToLoad; 

};

UCLASS()
class UFortPlaylist : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 PlaylistId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName PlaylistName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MinPlayers;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxPlayers;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxTeamCount;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxTeamSize;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxSocialPartySize;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxSquadSize;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxSquads;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool EnforceSquadFill;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bAllowSquadFillOption;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bAllowJoinInProgress;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText JoinInProgressMatchType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bAllowBroadcasting;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UPlaylistUserOptions* UserOptions;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<TSoftObjectPtr<UWorld>> AdditionalLevels;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    uint8 DefaultFirstTeam;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    uint8 DefaultLastTeam;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer GameplayTagContainer;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EFriendlyFireType FriendlyFireType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bUseFriendlyFireAimAssist;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 LootLevel;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagQuery LootTagQuery;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 BuildingLevelOverride;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDBNOType DBNOType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float SpawnImmunityTime;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<EAthenaGamePhaseStep> SkippedGamePhaseNotification;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<TSoftObjectPtr<UFortGameplayModifierItemDefinition>> ModifierList;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftClassPtr<AFortTimeOfDayManager> TimeOfDayManager;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<UFortWorldItemDefinition*> ItemsToFullyLoad;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFortSharedAssetGroup* SharedAssetGroup;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFortConditionalAssetGroup* ConditionalAssetGroup;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bIsDefaultPlaylist;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText UIDisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText UIDescription;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer HUDElementsToHide;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftObjectPtr<UDataTable> LootTierData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftObjectPtr<UDataTable> LootPackages;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftObjectPtr<UDataTable> RangedWeapons;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftObjectPtr<UCurveTable> GameData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftObjectPtr<UCurveTable> ResourceRates;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float GarbageCollectionFrequency;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ServerPerformanceEventFrequency;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ServerMetricsEventFrequency;
};
