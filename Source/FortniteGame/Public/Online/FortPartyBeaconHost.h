#pragma once
#include "CoreMinimal.h"
#include "PartyBeaconHost.h"
#include "FortPartyBeaconHost.generated.h"

USTRUCT(BlueprintType)
struct FPlayerSquadMapping {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FString PlayerID;
    
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	uint32 TeamId;
    
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	uint32 PartyId;
};

UCLASS(Blueprintable, NonTransient)
class AFortPartyBeaconHost : public APartyBeaconHost {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FPlayerSquadMapping> PlayerSquadMapping;
    
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bUseSquadMappingOverride;
    
	AFortPartyBeaconHost();
};

