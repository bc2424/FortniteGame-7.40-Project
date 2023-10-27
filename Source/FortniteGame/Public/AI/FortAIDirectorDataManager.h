#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/CurveTable.h"
#include "FortniteGame.h"
#include "FortAIDirectorDataManager.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAIDirectorEventData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortAIDirectorEvent Event;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCurveTableRowHandle DataMax;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FCurveTableRowHandle CoolDownRate;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortAIDirectorEventContribution ContributionType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortAIDirectorEventParticipant OwnerParticipantType;
};

USTRUCT(BlueprintType)
struct FFortAIDirectorFactorContribution {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortAIDirectorEvent AIDirectorEvent;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MaxContribution;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortAIDirectorFactorContribution::Type> ContributionType;
};

USTRUCT(BlueprintType)
struct FFortAIDirectorFactorData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortAIDirectorFactor AIDirectorFactor;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAIDirectorFactorContribution> ContributingEvents;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float MaxValue;
};

USTRUCT(BlueprintType)
struct FFortAIDirectorEvent {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EFortAIDirectorEvent Event;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UObject* EventSource;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UObject* EventTarget;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float EventValue;
};

UCLASS(Abstract, Blueprintable)
class AFortAIDirectorDataManager : public AActor {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UObject* OwnerObject;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FAIDirectorEventData> EventsToTrack;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortAIDirectorFactorData> FactorsToTrack;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<EFortAIDirectorFactor> FactorsBeingTracked;
    
public:
	AFortAIDirectorDataManager();
	UFUNCTION(BlueprintCallable)
	void TriggerEvent(const FFortAIDirectorEvent& TriggeredEvent);
    
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetAIDirectorFactorValue(EFortAIDirectorFactor AIDirectorFactor) const;
    
};

