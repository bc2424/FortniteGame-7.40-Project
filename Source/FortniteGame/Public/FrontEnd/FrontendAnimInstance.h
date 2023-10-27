// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Animation/AnimInstance.h"
#include "FortniteGame.h"
#include "HeadPartAnimInstance.h"
#include "FrontendAnimInstance.generated.h"

UCLASS()
class UFrontendAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsSkydiving;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFortAnimInput_Facial FacialInput;

	UPROPERTY(EditAnywhere)
	AFortPlayerPawn* FortPlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EFortDisplayGender Gender;
	
	UPROPERTY(EditAnywhere)
	class UAnimMontage* IntroAnimation_Female;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* IntroAnimation_Male;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* OutroAnimation_Female;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* OutroAnimation_Male;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* SelectedAnimation_Female;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* SelectedAnimation_Male;

	UPROPERTY(BlueprintReadWrite)
	bool bCanPlayCustomAnimations;
	
	UPROPERTY(EditAnywhere)
	struct FGameplayTagAnimations GameplayTagAnimations;

	UPROPERTY(EditAnywhere)
	struct FGameplayTagAnimations FemaleGameplayTagAnimations;

	UPROPERTY(EditAnywhere)
	struct FGameplayTagAnimations MaleGameplayTagAnimations;
};

