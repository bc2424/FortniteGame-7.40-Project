// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItem.h"
#include "AthenaCosmeticItemDefinition.h"
#include "AthenaCosmeticAccountItem.generated.h"

USTRUCT()
struct FMcpVariantReader
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	 FString Channel;

	UPROPERTY(EditAnywhere)
	 FString Active;

	UPROPERTY(EditAnywhere)
	TArray<FString> Owned;
};

UCLASS()
class UAthenaCosmeticAccountItem : public UFortAccountItem
{
	GENERATED_BODY()
public:
	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> VariantChannels;
	
	UPROPERTY(EditAnywhere)
	TArray<FMcpVariantReader> Variants;
};
