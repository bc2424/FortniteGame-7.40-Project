#pragma once
#include "CoreMinimal.h"
#include "NetReplicationGraphConnection.h"
#include "FortReplicationGraphConnection.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFortReplicationGraphConnection : public UNetReplicationGraphConnection {
    GENERATED_BODY()
public:
    UFortReplicationGraphConnection();
};

