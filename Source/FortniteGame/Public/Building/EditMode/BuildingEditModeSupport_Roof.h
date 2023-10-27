#pragma once
#include "CoreMinimal.h"
#include "BuildingEditModeSupport_BinaryToggle.h"
#include "BuildingEditModeSupport_Roof.generated.h"

USTRUCT(BlueprintType)
struct FTileCompInterpData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector InitialTranslation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector DesiredTranslation;
};

UCLASS(Blueprintable)
class UBuildingEditModeSupport_Roof : public UBuildingEditModeSupport_BinaryToggle {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<FTileCompInterpData> TileInterpData;
};

