// All fortnites reserved AllyJax

#include "Projectiles/FortProjectileBase.h"
#include "Components/CapsuleComponent.h"
//#include "BulletWhipTrackerComponentBase.h"


// Sets default values
AFortProjectileBase::AFortProjectileBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule0"));
	ProjectileMovementComponent = CreateDefaultSubobject<UFortProjectileMovementComponent>(TEXT("ProjectileComp0"));
	RootComponent = CapsuleComponent;

}

// Called when the game starts or when spawned
void AFortProjectileBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFortProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
