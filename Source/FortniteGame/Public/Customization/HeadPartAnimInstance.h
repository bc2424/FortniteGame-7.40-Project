// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomCharacterPartAnimInstance.h"
#include "HeadPartAnimInstance.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortAnimInput_Facial 
{
	GENERATED_BODY()
public:
	//UPROPERTY(EditAnywhere)
	//FLiveLinkSubjectName SubjectName; 

	UPROPERTY(EditAnywhere)
	EFortFacialAnimTypes CurrentAnimType;

	UPROPERTY(EditAnywhere)
	bool bCurvesOnly; 

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UHeadPartAnimInstance : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FFortAnimInput_Facial FacialInput;
};