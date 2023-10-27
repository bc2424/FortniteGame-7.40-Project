#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortniteGame.h"
#include "FortAnimNotifyState_AbilityDecisionWindow.generated.h"

USTRUCT(BlueprintType)
struct FFortMontageInputAction
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag TriggerAbilityTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName NextSection;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EFortMontageInputType InputType;
	FORTNITEGAME_API FFortMontageInputAction();
};


UCLASS()
class FORTNITEGAME_API UFortAnimNotifyState_AbilityDecisionWindow : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FFortMontageInputAction PrimaryInput;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FFortMontageInputAction SecondaryInput;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName DefaultNextSection;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float PrimaryInputStrikeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float SecondaryInputStrikeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 ComboCounter;

	    
	UFortAnimNotifyState_AbilityDecisionWindow();
};
