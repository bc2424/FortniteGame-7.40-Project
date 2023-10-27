#pragma once
#include "CoreMinimal.h"
#include "EFortRequestedGameplayAction.generated.h"

UENUM(BlueprintType)
namespace EFortRequestedGameplayAction {
    enum Type {
        ContinuePlaying,
        StartPlaying,
        StopPlaying,
        EnterZone,
        LeaveZone,
        ReturnToMainMenu,
        QuitGame,
        Invalid,
    };
}

