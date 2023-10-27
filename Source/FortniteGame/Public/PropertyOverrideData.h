#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "FortniteGame.h"
#include "PropertyOverrideData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FPropertyOverrideMk2 : public FFastArraySerializerItem {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FString PropertyScope;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FString PropertyName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	FString PropertyData;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	FString DefaultPropertyData;
};

USTRUCT(BlueprintType)
struct FPropertyOverrideData : public FFastArraySerializer {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
	TArray<FPropertyOverrideMk2> PropertyOverrides;
    
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, Transient, meta=(AllowPrivateAccess=true))
	int32 TargetObjectReplicationKey;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	EPropertyOverrideTargetType OverrideMode;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	UObject* BaseObject;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, Transient, meta=(AllowPrivateAccess=true))
	UObject* MutableObject;
};

