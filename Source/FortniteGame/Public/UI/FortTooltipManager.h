#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/DataAsset.h"
#include "FortTooltipManager.generated.h"

class AActor;
class UFortTooltip;

USTRUCT(BlueprintType)
struct FFortTooltipMapEntry {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UClass* ObjectClass;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UClass* SecondaryObjectClass;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSubclassOf<UFortTooltip> TooltipClass;
};
UCLASS(Blueprintable)
class UFortTooltipMap : public UDataAsset {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortTooltipMapEntry> Mapping;
};
UCLASS(Blueprintable)
class FORTNITEGAME_API UFortTooltipManager : public UObject {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TMap<UClass*, UFortTooltip*> Tooltips;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	AActor* DamageRecieverProxy;
    
public:
	UFortTooltipManager();
};

