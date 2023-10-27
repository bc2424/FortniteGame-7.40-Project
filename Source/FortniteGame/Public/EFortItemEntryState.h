#pragma once
#include "CoreMinimal.h"
#include "EFortItemEntryState.generated.h"

UENUM(BlueprintType)
namespace EFortItemEntryState {
    enum Type {
        NoneState,
        NewItemCount,
        ShouldShowItemToast,
        DurabilityInitialized,
        DoNotShowSpawnParticles,
        FromRecoveredBackpack,
        FromGift,
        PendingUpgradeCriteriaProgress,
        OwnerBuildingHandle,
        FromDroppedPickup,
        JustCrafted,
        CraftAndSlotTarget,
        GenericAttributeValueSet,
        PickupInstigatorHandle,
    };
}

