#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "AttributeSet.h"
#include "FortTieredCollectionLayout.generated.h"

class UFortTieredCollectionLayout;
class UFortBadgeItemDefinition;

USTRUCT(BlueprintType)
struct FTieredCollectionProgressionDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECollectionSelectionMethod SelectionMethod;
};

USTRUCT(BlueprintType)
struct FTieredNamedCollectionProgressionData : public FTieredCollectionProgressionDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CollectionNames;
};

USTRUCT(BlueprintType)
struct FDifficultyRowProgression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DifficultyRowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScalableFloat AdditiveDifficultyMod;
};

USTRUCT(BlueprintType)
struct FDifficultyCollectionProgressionData : public FTieredCollectionProgressionDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDifficultyRowProgression> DifficultyCollections;
};

USTRUCT(BlueprintType)
struct FRewardBadgesProgression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFortBadgeItemDefinition*> RewardBadges;
};

USTRUCT(BlueprintType)
struct FRewardBadgesCollectionProgressionData : public FTieredCollectionProgressionDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRewardBadgesProgression> BadgeCollections;
};

USTRUCT(BlueprintType)
struct FCollectionLootSetData : public FTieredCollectionProgressionDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LootSetNames;
};


UCLASS(Blueprintable)
class FORTNITEGAME_API UFortTieredCollectionLayout : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseTierAsRandomSeed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFiniteTiers: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxNumberOfTiersAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialTierUnlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTieredNamedCollectionProgressionData SpawnWaveProgressions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDifficultyCollectionProgressionData DifficultyProgressions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTieredNamedCollectionProgressionData ModifierProgressions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRewardBadgesCollectionProgressionData RewardBadgesProgression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCollectionLootSetData LootSetProgression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CollectionLayoutDisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFortTieredCollectionLayout> PrerequisiteLayout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurveTableRowHandle TierToMissionPointLookupTable;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid LayoutGUID;
    
public:
    UFortTieredCollectionLayout();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldUseTierAsRandomSeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMissionPointsForTier(int32 Tier) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetCollectionLayoutDisplayName() const;
};

