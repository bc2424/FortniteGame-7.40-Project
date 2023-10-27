#pragma once
#include "CoreMinimal.h"
#include "CustomCosmeticModifierBase.h"
#include "EFortCustomPartType.h"
#include "EFortDayPhase.h"
#include "CustomCharacterPartModifier.generated.h"

class AFortPlayerPawn;
class UMeshComponent;

UCLASS(Abstract, Blueprintable, MinimalAPI)
class ACustomCharacterPartModifier : public ACustomCosmeticModifierBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUsesDayPhaseChange: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUsesTargetingOrFirstPersonCameraChange: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bRegisteredForDayPhaseChange: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bRegisteredForSkydiving: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bRegisteredForTargetingOrFirstPersonCamera: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFortCustomPartType::Type> PartType;
    
public:
    ACustomCharacterPartModifier();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void PreDestruction();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnTargetingOrFirstPersonCameraChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnPawnAndPartChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnEndSkydiving();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnDayPhaseChanged(TEnumAsByte<EFortDayPhase::Type> CurrentDayPhase, TEnumAsByte<EFortDayPhase::Type> PreviousDayPhase, bool bAtCreation);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnBeginSkydiving();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleSetFirstPersonCameraOrPawnTargetingChanged(bool bChanged);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMeshComponent* GetSkeletalMeshForAssociatedPlayerPawnPartType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EFortCustomPartType::Type> GetCharacterPartType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AFortPlayerPawn* GetAssociatedPlayerPawn() const;
    
};

