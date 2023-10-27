#pragma once
#include "CoreMinimal.h"
#include "FortAbilitySet.h"
#include "GamePlayTags.h"
#include "GameplayEffectTypes.h"
#include "FortniteGame.h"
#include "FortGameplayAbility_Structs.h"
#include "FortAbilitySetDeliveryInfo.generated.h"

class UFortAbilitySet;

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortDeliveryInfoRequirementsFilter {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagRequirements SourceTagRequirements;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagRequirements TargetTagRequirements;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortTeamAffiliation::Type> ApplicableTeamAffiliation;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bConsiderTeamAffiliationToInstigator: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortTeam::Type> ApplicableTeam;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bConsiderTeam: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bApplyToPlayerPawns: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bApplyToAIPawns: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bApplyToBuildingActors: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortDeliveryInfoBuildingActorSpecification BuildingActorSpecification;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 bApplyToGlobalEnvironmentAbilityActor: 1;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortAbilitySetDeliveryInfo {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortDeliveryInfoRequirementsFilter DeliveryRequirements;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<TSoftObjectPtr<UFortAbilitySet>> AbilitySets;
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortGameplayEffectDeliveryInfo {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortDeliveryInfoRequirementsFilter DeliveryRequirements;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FGameplayEffectApplicationInfo> GameplayEffects;
};

