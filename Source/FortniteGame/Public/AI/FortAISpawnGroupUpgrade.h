#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "Engine/CurveTable.h"
#include "Styling/SlateColor.h"
#include "FortAI_Structs.h"
#include "FortAISpawnGroupUpgrade.generated.h"

USTRUCT(BlueprintType)
struct FFortAIPawnUpgrade {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery TagQuery;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAIPawnUpgradeData> PawnUpgradeDataPerPlayerCount;
};

UCLASS(Blueprintable)
class UFortAISpawnGroupUpgrade : public UObject {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer UpgradeTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagQuery GroupRequiredTagQuery;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAIPawnUpgrade> BasePawnUpgrades;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName AdditionalModifiersLootTierGroup;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bInvalidForEnemySpawners;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float SpawnGroupDiscountPercentage;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortAISpawnGroupUpgradeUIData UIData;
};

