#pragma once
#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "FortGameSession.h"
#include "FortGameSessionDedicated.generated.h"

USTRUCT(BlueprintType)
struct FClientIdRestrictions {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FString ClientId;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FString> RestrictedPlatforms;
};

UCLASS(Blueprintable)
class FORTNITEGAME_API AFortGameSessionDedicated : public AFortGameSession {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bEnforceCrossplayRestrictions;
    
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bAllowPS4InMixedConsole;
    
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	float HotfixCheckTimer;
    
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	float HotfixCheckVariance;
    
private:
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	float ConsoleSessionRetryWaitSeconds;
    
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	EServerManifestOutputFormat ServerManifestOutputFormat;
    
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	FString ServerManifestDestination;
    
protected:
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	float IdleResetShortTimer;
    
private:
	UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FClientIdRestrictions> ClientIdRestrictions;
    
public:
	AFortGameSessionDedicated();
};

