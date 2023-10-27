#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortniteGame.h"
#include "LevelSaveSpawnable.h"
#include "Templates/SubclassOf.h"
#include "FortMinigameLogicComponent.generated.h"

class AFortMinigame;
class UFortMinigameStatFilter;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameAssignmentChanged, AFortMinigame*, Minigame);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleDynamicMulticastDelegate);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameStateChanged, EFortMinigameState, NewMinigameState);
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayspaceEditModeChanged, bool, bInEditMode);

UCLASS(Blueprintable, ClassGroup=Custom, Config=Creative, meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortMinigameLogicComponent : public UActorComponent, public ILevelSaveSpawnable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnMinigameStateChanged MinigameStateChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSimpleDynamicMulticastDelegate MinigameStartedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSimpleDynamicMulticastDelegate MinigameEndedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnPlayspaceEditModeChanged OnPlayspaceEditModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnMinigameAssignmentChanged OnAddedToMinigame;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FOnMinigameAssignmentChanged OnRemovedFromMinigame;
    
    UPROPERTY(BlueprintReadWrite, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MinigameTags;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UFortMinigameStatFilter>> DesiredStats;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=HandleMinigameSet, meta=(AllowPrivateAccess=true))
    AFortMinigame* CurrentMinigame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortMinigame* CachedMinigame;
    
public:
    UFortMinigameLogicComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    bool TryAttachToMinigame();
    
    UFUNCTION(BlueprintCallable)
    void RemoveMinigameTag(const FGameplayTag& Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandlePlayspaceEditModeChange(bool bInEditMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameStateChanged(EFortMinigameState NewMinigameState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameStarted();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameSet();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleMinigameEnded();
    
    UFUNCTION(BlueprintCallable)
    void AddMinigameTag(const FGameplayTag& Tag);
};

