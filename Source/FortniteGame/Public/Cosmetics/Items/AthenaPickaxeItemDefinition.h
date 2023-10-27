// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "AthenaPickaxeItemDefinition.generated.h"

/**
 * 
 */
USTRUCT()
struct FORTNITEGAME_API FFortUICameraFrameTargetBounds
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	 FVector Origin;                                           

	UPROPERTY(EditAnywhere)
	float CylinderHalfHeight;                                
	
	UPROPERTY(EditAnywhere)
	float CylinderRadius;                                   
};

UCLASS()
class FORTNITEGAME_API UAthenaPickaxeItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaPickaxeItemDefinition();
	UPROPERTY(EditAnywhere)
	class UFortWeaponMeleeItemDefinition*        WeaponDefinition;                                  // 0x430(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(EditAnywhere,Category = "Frontend Preview")
	 FVector                               PickaxeImpactFXPreviewOffset;                      // 0x438(0xC)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(EditAnywhere,Category = "Frontend Preview")
	FVector                               PickaxeDualWieldPreviewOffset;                     // 0x444(0xC)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(EditAnywhere,Category = "Frontend Preview")
	FRotator                              PickaxeDualWieldPreviewRotation; 

	UPROPERTY(EditAnywhere,Category = "Bounds")
	 FFortUICameraFrameTargetBounds        CameraFramingBounds;                               // 0x444(0x14)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, NativeAccessSpecifierPublic)

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaPickaxe", GetFName());
	}
};
