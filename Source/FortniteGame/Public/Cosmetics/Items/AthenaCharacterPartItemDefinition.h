
#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Customization/CustomCharacterPart.h"
#include "AthenaCharacterPartItemDefinition.generated.h"

UCLASS(Abstract, Blueprintable)
class FORTNITEGAME_API UAthenaCharacterPartItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
		TArray<UCustomCharacterPart*> CharacterParts;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UCustomCharacterPart*> GetCharacterParts() const;
};
