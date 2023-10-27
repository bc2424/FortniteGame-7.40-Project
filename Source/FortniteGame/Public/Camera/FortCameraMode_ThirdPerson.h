// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.
// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCameraMode.h"
#include "FortCameraMode_ThirdPerson.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortCameraMode_ThirdPerson : public UFortCameraMode
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        FOV;                                               // 0x50(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        CameraSpaceForwardDistance;                        // 0x54(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool                                         bClampCameraPitch;                                 // 0x58(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool                                         bClampCameraYaw;                                   // 0x59(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        CameraPitchMin;                                    // 0x5C(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        CameraPitchMax;                                    // 0x60(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        CameraYawMin;                                      // 0x64(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        CameraYawMax;                                      // 0x68(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECameraOrigin								 CameraOrigin;                                      // 0x6C(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName										 CameraOriginSocketName;                            // 0x70(0x8)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 CameraOriginInterpSpeed;                           // 0x78(0xC)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInterpOffset								 ViewTargetSpaceViewOffset;                         // 0x88(0x10)(Edit, BlueprintVisible, Protected, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInterpOffset								 ViewTargetSpaceViewOffset_Crouch;                  // 0x98(0x10)(Edit, BlueprintVisible, Protected, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 ViewTargetSpaceViewOffseInterpSpeed;               // 0xA8(0xC)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInterpOffset								 CameraSpaceViewOffset;                             // 0xB8(0x10)(Edit, BlueprintVisible, Protected, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        ViewTargetAlignmentFlipInterpDuration;             // 0xC8(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool                                         bSupportsShoulderSwap;                             // 0xCC(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 LastCameraOrigin;                                  // 0x100(0xC)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 CameraOriginLocalOffset;                           // 0x10C(0xC)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        PenetrationBlendInTime;                            // 0x118(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        PenetrationBlendOutTime;                           // 0x11C(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool                                         bPreventPenetration;                               // 0x120(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool                                         bDoPredictiveAvoidance;                            // 0x121(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        CollisionPushOutDistance;                          // 0x124(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        HidePawnPenetrationPercent;                        // 0x128(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName										 LastAttachSocketName;                              // 0x160(0x8)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FMinimalViewInfo							 LastBasePOV;                                       // 0x170(0x530)(Transient, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FMinimalViewInfo							 DeltaBasePOV;                                      // 0x6A0(0x530)(Transient, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        BlendAlpha;                                        // 0xBD0(0x4)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FPenetrationAvoidanceFeeler>			 PenetrationAvoidanceFeelers;                       // 0xBE8(0x10)(Edit, ZeroConstructor, DisableEditOnInstance, Protected, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        SafeLocToAimLineBlockedPct;                        // 0xBF8(0x4)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        AimLineToDesiredPosBlockedPct;                     // 0xBFC(0x4)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        LastDrawDebugTime;                                 // 0xC00(0x4)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 LastViewTargetSpaceViewOffset;                     // 0xC04(0xC)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 LastViewTargetAlignmentUp;                         // 0xC10(0xC)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float                                        ViewTargetAlignmentFlipInterpTime;                 // 0xC1C(0x4)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector										 LastCameraPivot;                                   // 0xC20(0xC)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor*										 IgnoreActorForCameraPenetration;                   // 0xC30(0x8)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool										 bWasInVehicle;										// Mask: 0x1, PropSize: 0x10xC38(0x1)(Transient, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor*										 PreviousIgnoreActorForCameraPenetration;           // 0xC40(0x8)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

};
