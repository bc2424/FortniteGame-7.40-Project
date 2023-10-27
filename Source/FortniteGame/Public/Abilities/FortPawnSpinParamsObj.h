#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FortPawnSpinParamsObj.generated.h"

class UFortPawnSpinParamsObj;

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortPawnSpinParams {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float LocalSpin;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bOnlySpinWhenFalling;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API UFortPawnSpinParamsObj : public UObject {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
	uint8 bReplicatedFlag: 1;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FFortPawnSpinParams SpinParams;
    
	UFortPawnSpinParamsObj();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static UFortPawnSpinParamsObj* BP_CreateFortPawnSpinParamsObjInstance(UObject* WorldContextObject);
    
};

