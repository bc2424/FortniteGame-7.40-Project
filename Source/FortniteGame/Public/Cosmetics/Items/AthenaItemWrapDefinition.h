// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Customization/CustomItemWrapModifier.h"
#include "AthenaItemWrapDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaItemWrapDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Item Wrap")
		TSoftClassPtr<ACustomItemWrapModifier> ItemWrapModifierBlueprint;
public:
	UAthenaItemWrapDefinition();
	UPROPERTY(EditAnywhere, Category = "Item Wrap")
		TSoftObjectPtr<UMaterialInterface> ItemWrapMaterial;
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaItemWrap", GetFName());
	}
};
