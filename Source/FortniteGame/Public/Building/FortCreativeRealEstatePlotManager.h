#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FortCreativeRealEstatePlotItemDefinition.h"
#include "FortCreativeRealEstatePlotManager.generated.h"

USTRUCT(BlueprintType)
struct FActiveRealEstatePlotInfo {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UFortCreativeRealEstatePlotItemDefinition* Plot;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FVector Position;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API AFortCreativeRealEstatePlotManager : public AInfo {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
	TArray<FActiveRealEstatePlotInfo> ActiveCreativeRealEstatePlots;
    
public:
	AFortCreativeRealEstatePlotManager();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
};

