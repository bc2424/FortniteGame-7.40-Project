#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "FortBadgeItemDefinition.h"
#include "FortBadgeCount.generated.h"

class UFortBadgeItemDefinition;

USTRUCT(BlueprintType)
struct FFortBadgeCount : public FFastArraySerializerItem {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	UFortBadgeItemDefinition* Badge;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	int32 Count;
};

