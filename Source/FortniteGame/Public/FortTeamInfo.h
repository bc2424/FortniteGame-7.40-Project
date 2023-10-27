#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Info.h"
#include "FortTeamActorInterface.h"
#include "Engine/NetSerialization.h"
#include "FortTeamInfo.generated.h"

class AActor;
class AController;
class AFortTeamPrivateInfo;
class UPrimitiveComponent;

class AFortTeamInfo;
class AActor;
class AFortPlayerController;

USTRUCT(BlueprintType)
struct FTeamSpottedActorInfo : public FFastArraySerializerItem {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, meta=(AllowPrivateAccess=true))
	AFortPlayerController* Spotter;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	AActor* SpottedActor;
};
USTRUCT(BlueprintType)
struct FTeamSpottedActorInfoArray : public FFastArraySerializer {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FTeamSpottedActorInfo> SpottedActorInfo;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, meta=(AllowPrivateAccess=true))
	AFortTeamInfo* OwningTeam;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API AFortTeamInfo : public AInfo, public IFortTeamActorInterface {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<AController*> TeamMembers;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
	uint8 Team;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
	FString ChatRoomId;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
	FTeamSpottedActorInfoArray TeamSpottedActors;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
	AFortTeamPrivateInfo* PrivateInfo;
    
public:
	AFortTeamInfo();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
	UFUNCTION(BlueprintCallable)
	void OnSpottedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);
    
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetTeamLevel() const;
    
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetTeamExperience() const;
    
    
	// Fix for true pure virtual functions not being implemented
	UFUNCTION()
	uint8 GetTeam() const override PURE_VIRTUAL(GetTeam, return 0;);
    
};

