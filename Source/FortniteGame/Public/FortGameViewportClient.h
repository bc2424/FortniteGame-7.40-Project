#pragma once

#include "Engine/GameViewportClient.h"
#include "FortGameViewportClient.generated.h"

UCLASS()
class UFortGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
public:
	UPROPERTY(Transient)
	 FText NetworkFailureMessage;

	UPROPERTY(Transient)
	 FString NetworkFailureMessageAdditionalAnalyticsString;
};





