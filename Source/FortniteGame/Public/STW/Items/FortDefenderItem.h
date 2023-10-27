#pragma once
#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "FortCharacter.h"
#include "FortDefenderItem.generated.h"

class UFortAlterationItemDefinition;

UCLASS(Blueprintable, MinimalAPI)
class UFortDefenderItem : public UFortCharacter {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FString> Alterations;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<UFortAlterationItemDefinition*> AlterationInstances;
    
public:
	UFortDefenderItem();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	EFortDefenderSubtype GetDefenderSubtype() const;
    
};

