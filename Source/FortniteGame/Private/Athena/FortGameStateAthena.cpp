// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#include "FortGameStateAthena.h"
#include "Net/UnrealNetwork.h"

void AFortGameStateAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate
	DOREPLIFETIME(AFortGameStateAthena, bIsLargeTeamGame);
}