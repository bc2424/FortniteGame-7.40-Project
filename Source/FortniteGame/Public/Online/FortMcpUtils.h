#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FortMcpUtils.generated.h"

UCLASS(Blueprintable, Config=Game)
class FORTNITEGAME_API UFortMcpUtils : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CreateXboxDedicatedServerSessionUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UnredeemedCodesUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString QueryUserXuidUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RecordUserStatsUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString QueryUserStatsUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString QueryLeaderboardUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString QueryCohortUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString InMatchTimePlayedUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ProcessPendingRewardsUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldSendTimeTracking;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString VoiceLoginUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString VoiceJoinUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UpdateMatchmakingRatingUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PrivacySettingsUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AllowHomebaseCharactersUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString QuerySwitchEntitlementsUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReportPlayerToxicityUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventCalendardTestUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CreativeHistoryBaseUrl;
    
    UPROPERTY(BlueprintReadOnly, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultLogTailLengthKb;
public:
    UFortMcpUtils();
};

