#pragma once
#include "CoreMinimal.h"
#include "ClientUrlContext.h"
#include "ESocialImportPanelPlatform.h"
#include "FortMcpProfile.h"
#include "FortMcpProfileCommonCore.generated.h"

UCLASS(Blueprintable, Config=Game)
class FORTNITEGAME_API UFortMcpProfileCommonCore : public UFortMcpProfile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ListCatalogEntriesUrl;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AffiliateExpirationSeconds;
    
public:
    UFortMcpProfileCommonCore();
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void TwitchUpdateBroadcasterRegistration(const FString& AccessToken, const FString& ChannelId, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void SetReceiveGiftsEnabled(bool bReceiveGifts, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void SetMtxPlatform(const FString& NewPlatform, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void SetMatchmakingBansViewed(UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void SetAffiliateName(const FString& AffiliateName, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void RemoveGiftBox(const FString& GiftBoxItemId, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void RefundMtxPurchase(const FString& PurchaseId, bool QuickReturn, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void IssueFriendCode(const FString& CodeTokenType, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void CompletePlayerSurvey(const FString& SurveyID, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void ClaimMfaEnabled(bool bClaimForStw, UPARAM(NotReplicated) FClientUrlContext& Context);
    
    UFUNCTION(BlueprintCallable, Reliable, ServiceRequest=null)
    void ClaimImportFriendsReward(ESocialImportPanelPlatform Network, UPARAM(NotReplicated) FClientUrlContext& Context);
    
};

