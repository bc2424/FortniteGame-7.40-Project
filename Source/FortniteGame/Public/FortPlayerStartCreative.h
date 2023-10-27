#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "GameplayTagContainer.h"
#include "FortPlayerStartCreative.generated.h"

class UFortCreativeVolumeLinkComponent;

UCLASS(Blueprintable)
class FORTNITEGAME_API AFortPlayerStartCreative : public APlayerStart {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer PlayerStartTags;
    
	UPROPERTY(EditAnywhere)
	int32 PortalIndex;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	uint8 ApplicableTeam;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bUseAsIslandStart;
    
	UPROPERTY(EditAnywhere)
	int32 PriorityGroup;
    
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
	UFortCreativeVolumeLinkComponent* CreativeLinkComponent;
};

