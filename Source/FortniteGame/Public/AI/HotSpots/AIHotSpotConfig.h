// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AIHotSpotSlotGenerator.h"
#include "AIHotSpotConfig.generated.h"

UENUM()
enum class EFortHotSpotSlot : uint8
{
	Melee = 0,
	MeleeHuge = 1,
	Ranged = 2,
	None = 3,
	EFortHotSpotSlot_MAX = 4 UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FAIHotSpotSlotConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFortHotSpotSlot SlotType;
};

UCLASS()
class UAIHotSpotConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FAIHotSpotSlotConfig> Slots;

	UPROPERTY(EditAnywhere)
	bool bDetectUnreachableSlots;

	UPROPERTY(EditAnywhere, Instanced)
	UAIHotSpotSlotGenerator* SlotGenerator;
};