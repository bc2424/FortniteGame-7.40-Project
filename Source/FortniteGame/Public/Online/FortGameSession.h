#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "PartyBeaconState.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Templates/SubclassOf.h"
#include "FortGameSession.generated.h"

class AFortLobbyBeaconHost;
class AFortMeshBeaconClient;
class AFortMeshBeaconHost;
class AFortMeshBeaconHostObject;
class AFortPartyBeaconHost;
class AFortSpectatorBeaconHost;
//class AOnlineBeaconHostObject;

USTRUCT(BlueprintType)
struct FFortDisconnectedPlayerReservation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SessionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUniqueNetIdRepl PlayerID;
};

USTRUCT(BlueprintType)
struct FFortHostSessionParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SessionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ControllerId;
};


UCLASS(Blueprintable)
class FORTNITEGAME_API AFortGameSession : public AGameSession {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFortHostSessionParams CurrentSessionParams;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
  //  TSubclassOf<AOnlineBeaconHostObject> ReservationBeaconHostClass;
    
  //  UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    TSubclassOf<AOnlineBeaconHostObject> SpectatorBeaconHostClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortPartyBeaconHost* ReservationBeaconHost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortLobbyBeaconHost* LobbyBeaconHost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortSpectatorBeaconHost* SpectatorBeaconHost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FFortDisconnectedPlayerReservation> DisconnectedPlayerReservations;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlayerReservation> PlayersToRegister;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulkUnregisterTimerDelay;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxBroadcasters;
    
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisconnectedReservationTimeout;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldServerForcePartnerId;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ServerForcePartnerId;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableMeshNetwork;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> DisabledMeshNodeTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortMeshBeaconHost* MeshBeaconHost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortMeshBeaconHostObject* MeshBeaconHostObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortMeshBeaconClient* MeshBeaconClient;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RetryMeshConnectDelay;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxMeshConnectDelay;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshNetworkServerStatusEventRate;
    
public:
    AFortGameSession();
    UFUNCTION(BlueprintCallable, Exec)
    void DumpReservations() const;
};

