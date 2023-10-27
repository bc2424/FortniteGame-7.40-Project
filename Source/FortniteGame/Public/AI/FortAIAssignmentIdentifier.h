#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortniteGame.h"
#include "FortAIAssignmentIdentifier.generated.h"

USTRUCT(BlueprintType)
struct FFortAIAssignmentIdentifier {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	EAssignmentType AssignmentType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer AssignmentGameplayTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EFortTeam::Type> AssignmentTeam;
};

