#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuildingAutoNav.h"
#include "BuildingTimeOfDayLights.generated.h"

class ULightComponent;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FTimeOfDayBlueprintDefaultVariables {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UStaticMesh* AlternateShadowStaticMesh;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	float VolumetricLightScatteringIntensity;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bDisableTODLightsAndMaterialEmissiveValues;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bDisableStaticMeshShadowCastingWhenLightsAreActive;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bUseAnAlternateShadowMeshWhenTheLightIsOff;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	bool bCastVolumetricShadows;
};
UCLASS(Blueprintable, MinimalAPI)
class ABuildingTimeOfDayLights : public ABuildingAutoNav {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
	TArray<ULightComponent*> TimeOfDayControlledLights;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FVector> TimeOfDayControlledLightsPositions;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<float> TimeOfDayControlledLightsInitalIntensities;
    
public:
	ABuildingTimeOfDayLights();
protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void GetTimeOfDayBlueprintDefaultVariables(FTimeOfDayBlueprintDefaultVariables& OutVariables);
    
};

