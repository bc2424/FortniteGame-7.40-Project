// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortWeapon.h"

#include "SkeletalMeshComponentBudgeted.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AFortWeapon::AFortWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Creating the default weapon mesh */
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponentBudgeted>(TEXT("WeaponMesh0"));
	//LeftHandWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(L"Left Hand Weapon Mesh");
	RootComponent = WeaponMesh;

//	this->ReloadSounds[0] = FText::FromString(TEXT("Reload Start"));
//	this->ReloadSounds[1] = FText::FromString(TEXT("Reload Cartridge"));
//	this->ReloadSounds[2] = FText::FromString(TEXT("Reload End"));
}

// Called when the game starts or when spawned
void AFortWeapon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFortWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// uses the weapon's durability with a set scale
void AFortWeapon::UseWeaponDurability(float DurabilityScale)
{
	return;
}

// stops fire effects that are being played by this weapon
void AFortWeapon::StopWeaponFireFX()
{
	return;
}

// K2 notification when weapon is hidden/shown
void AFortWeapon::OnWeaponVisibilityChanged_Implementation(bool bVisible)
{
	return;
}

// stops fire effects that are being played by this weapon
void AFortWeapon::OnWeaponAttached_Implementation()
{
	return;
}

// Blueprint notification for when weapon starts charging
void AFortWeapon::OnStartCharge_Implementation()
{
	return;
}

// Blueprint notification for when the weapon ends its charge
void AFortWeapon::OnEndCharge_Implementation()
{
	return;
}

// Called when weapon charge starts to decrease
void AFortWeapon::OnChargeDown_Implementation()
{
	return;
}

// Called when weapon charge starts to increase
void AFortWeapon::OnChargeUp_Implementation()
{
	return;
}

// Blueprint notification that the weapon's ammo count has changed
void AFortWeapon::OnAmmoCountChanged_Implementation()
{
	return;
}

// Blueprint notification for when the weapon reaches the minimum charge value outlined by the stat table
void AFortWeapon::OnReachedMinCharge_Implementation()
{
	return;
}

// Blueprint notification for when the weapon reaches the maximum charge value outlined by the stat table
void AFortWeapon::OnReachedMaxCharge_Implementation()
{
	return;
}


void AFortWeapon::OnPlayWeaponFireFX_Implementation(bool bPersistentFire, bool bSecondaryFire)
{
	return;
}

void AFortWeapon::OnSetTargeting_Implementation(bool bNewIsTargeting)
{
	return;
}

void AFortWeapon::K2_OnUnEquip_Implementation()
{
	return;
}

void AFortWeapon::K2_ConsumeAmmo(int32 Quantity)
{
	return;
}

FGuid AFortWeapon::GetInventoryGUID()
{
	return WeaponGUID;
}

float AFortWeapon::GetChargePercent()
{
	return ChargePercent;
}
