#pragma once
#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "FortGameDeathPenalty.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortGameDeathPenalty : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentResourcesToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentWeaponsToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentCraftingIngredientsToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentConsumablesToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentAmmoToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentResourcesToRecover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentWeaponsToRecover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentCraftingIngredientsToRecover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentConsumablesToRecover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentAmmoToRecover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinResourcesToKeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinWeaponsToKeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinCraftingIngredientsToKeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinConsumablesToKeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinAmmoToKeep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurveTableRowHandle RespawnDelays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RespawnDelayOverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRespawnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSelfResurrectDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRegenHealthOnRespawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentHealthOnRespawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentStaminaOnRespawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RespawnDurabilityPenalty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelfResurrectDurabilityPenalty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeammateResurrectDurabilityPenalty;
    
public:
    UFortGameDeathPenalty() {
        this->PercentResourcesToDrop = 0.00f;
        this->PercentWeaponsToDrop = 0.00f;
        this->PercentCraftingIngredientsToDrop = 0.00f;
        this->PercentConsumablesToDrop = 0.00f;
        this->PercentAmmoToDrop = 0.00f;
        this->PercentResourcesToRecover = 1.00f;
        this->PercentWeaponsToRecover = 1.00f;
        this->PercentCraftingIngredientsToRecover = 1.00f;
        this->PercentConsumablesToRecover = 1.00f;
        this->PercentAmmoToRecover = 1.00f;
        this->MinResourcesToKeep = 0;
        this->MinWeaponsToKeep = 0;
        this->MinCraftingIngredientsToKeep = 0;
        this->MinConsumablesToKeep = 0;
        this->MinAmmoToKeep = 0;
        this->RespawnDelayOverTime = NULL;
        this->MaxRespawnDelay = 30.00f;
        this->MinSelfResurrectDelay = 10.00f;
        this->bUseRegenHealthOnRespawn = false;
        this->PercentHealthOnRespawn = 1.00f;
        this->PercentStaminaOnRespawn = 1.00f;
        this->RespawnDurabilityPenalty = 0.15f;
        this->SelfResurrectDurabilityPenalty = 0.05f;
        this->TeammateResurrectDurabilityPenalty = 0.05f;
    }
};

