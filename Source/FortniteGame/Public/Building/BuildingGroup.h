#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortniteGame.h"
#include "BuildingGroup.generated.h"

class UBuildingGroup;

USTRUCT(BlueprintType)
struct FFortMapData {
	GENERATED_BODY()
public:
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TSoftObjectPtr<UWorld> BuildingWorld;
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer BuildingLevelTags;
};

UCLASS(Blueprintable, EditInlineNew)
class FORTNITEGAME_API UBuildingGroup : public UDataAsset {
	GENERATED_BODY()
public:
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FName GroupName;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	UBuildingGroup* FallbackGroup;
    
	UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TEnumAsByte<EBuildingFoundationType> FoundationType;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FGameplayTagContainer AllBuildingLevelTags;
    
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	TArray<FFortMapData> BuildingLevelData;
    
	UBuildingGroup();
	UFUNCTION(BlueprintCallable)
	void GetAllMapNames(TArray<FString>& AllMaps);
    
};

