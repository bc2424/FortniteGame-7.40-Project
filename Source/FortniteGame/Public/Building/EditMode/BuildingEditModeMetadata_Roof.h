#pragma once
#include "CoreMinimal.h"
#include "BuildingEditModeMetadata_BinaryToggle.h"
#include "BuildingEditModeMetadata_Roof.generated.h"

USTRUCT(BlueprintType)
struct FAuxiliaryEditTileMeshData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UStaticMesh* TileMesh;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UTexture2D* TileTexture;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FRotator RelativeRot;
};

UCLASS(Blueprintable)
class UBuildingEditModeMetadata_Roof : public UBuildingEditModeMetadata_BinaryToggle {
	GENERATED_BODY()
public:
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FAuxiliaryEditTileMeshData> AuxEditTileMeshData;
};

