#pragma once
#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "BuildingStructuralSupportSystem.generated.h"

class ABuildingActor;
class ABuildingLayoutRequirement;
class ABuildingSMActor;
class AController;
class AFortNavigationGraph;
USTRUCT(BlueprintType)
struct FBuildingGridActorFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeWalls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeFloors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeFloorInTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeCenterCell;
};


USTRUCT(BlueprintType)
struct FBuildingSupportCellIndex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Y;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Z;
};

USTRUCT(BlueprintType)
struct FNeighboringWallInfo {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABuildingSMActor> NeighboringActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildingSupportCellIndex NeighboringCellIdx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStructuralWallPosition WallPosition;
};

USTRUCT(BlueprintType)
struct FNeighboringFloorInfo {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABuildingSMActor> NeighboringActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildingSupportCellIndex NeighboringCellIdx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStructuralFloorPosition FloorPosition;
};


USTRUCT(BlueprintType)
struct FNeighboringCenterCellInfo {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABuildingSMActor> NeighboringActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildingSupportCellIndex NeighboringCellIdx;
};

USTRUCT(BlueprintType)
struct FBuildingNeighboringActorInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNeighboringWallInfo> NeighboringWallInfos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNeighboringFloorInfo> NeighboringFloorInfos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNeighboringCenterCellInfo> NeighboringCenterCellInfos;
};


UCLASS(Blueprintable, MinimalAPI)
class UBuildingStructuralSupportSystem : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AController* BatchedRemovalInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABuildingLayoutRequirement*> LayoutRequirementActorsToRegister;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFortNavigationGraph* NavGraph;
    
public:
    UBuildingStructuralSupportSystem();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WouldBuildingBeStructurallySupportedByNeighbors(const ABuildingSMActor* ActorToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored) const;
    
    UFUNCTION(BlueprintCallable)
    void StopActorRemovalBatch();
    
    UFUNCTION(BlueprintCallable)
    void StartActorRemovalBatch();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetWorldLocFromGridIndices(const FBuildingSupportCellIndex& GridIndices, FVector& OutWorldLoc) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void K2_GetNeighboringBuildingActors(TEnumAsByte<EFortBuildingType::Type> BuildingType, const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void K2_GetNeighboringActorsForWallActor(const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void K2_GetNeighboringActorsForCenterCellActor(const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const;
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void K2_GetLogicalBuildingActors(int32 LogicalIdx, TArray<ABuildingSMActor*>& LogicalBuildingActors);
    
    UFUNCTION(BlueprintCallable)
    bool K2_GetGridIndicesFromWorldLoc(const FVector& WorldLoc, FBuildingSupportCellIndex& OutGridIndices);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox K2_GetGridBoxFromWorldLoc(const FVector& WorldLocation) const;
    
    UFUNCTION(BlueprintCallable)
    bool K2_GetBuildingActorsInGridCells(const TArray<FBuildingSupportCellIndex>& CellIndices, const FBuildingGridActorFilter& Filter, FBuildingNeighboringActorInfo& OutActorsInGridCell);
    
    UFUNCTION(BlueprintCallable)
    bool K2_GetBuildingActorsInGridCell(const FVector& WorldLocation, const FBuildingGridActorFilter& Filter, FBuildingNeighboringActorInfo& OutActorsInGridCell);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EFortStructuralGridQueryResults::Type> K2_CanAddWallActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, TEnumAsByte<EFortBuildingType::Type> WallType, EStructuralWallPosition& OutWallPosition, int32& OutWallIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbSupportedByWorld, bool bAllowStaticOverlap, bool bPerformCollisionChecks) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EFortStructuralGridQueryResults::Type> K2_CanAddFloorActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, TEnumAsByte<EFortBuildingType::Type> FloorType, EStructuralFloorPosition& OutFloorPosition, int32& OutFloorIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbSupportedByWorld, bool bAllowStaticOverlap, bool bPerformCollisionChecks) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EFortStructuralGridQueryResults::Type> K2_CanAddCenterCellActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, TEnumAsByte<EFortBuildingType::Type> CenterCellType, int32& OutHorizontalGridIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbStructurallySupported, bool bAllowStaticOverlap, bool bPerformCollisionChecks) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    TEnumAsByte<EFortStructuralGridQueryResults::Type> K2_CanAddBuildingActorToGrid(UObject* WorldContextObject, const ABuildingSMActor* ActorToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored, TArray<ABuildingActor*>& ExistingBuildings, EFortBuildPreviewMarkerOptionalAdjustment& MarkerOptionalAdjustment, bool bAllowStaticOverlap) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWorldLocValid(const FVector& WorldLoc) const;
    
private:
    UFUNCTION(BlueprintCallable)
    static bool IsBuildingActorValid(const ABuildingSMActor* ActorToTest);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBuildingActorStructurallySupported(const ABuildingSMActor* ActorToCheck) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABuildingSMActor* GetWallActor(const FBuildingSupportCellIndex& GridIndices, EStructuralWallPosition WallPosition) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void GetLogicalBuildingGroundSupportedActors(int32 LogicalIndex, TArray<ABuildingSMActor*>& LogicalBuildingGroundSupportedActors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetGridBox(const FBuildingSupportCellIndex& CellIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABuildingSMActor* GetFloorActor(const FBuildingSupportCellIndex& GridIndices, EStructuralFloorPosition FloorPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABuildingSMActor* GetCenterCellActor(const FBuildingSupportCellIndex& GridIndices) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    TEnumAsByte<EFortStructuralGridQueryResults::Type> CanAddBuildingActorClassToGrid(UObject* WorldContextObject, UClass* BuildingSMActorClassToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored, TArray<ABuildingActor*>& ExistingBuildings, EFortBuildPreviewMarkerOptionalAdjustment& MarkerOptionalAdjustment, bool bAllowStaticOverlap) const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreNeighborsConnected(const ABuildingSMActor* NeighborOne, const FVector& NeighborOneLoc, const FRotator& NeighborOneRot, bool bNeighborOneMirrored, const ABuildingSMActor* NeighborTwo, const FVector& NeighborTwoLoc, const FRotator& NeighborTwoRot, bool bNeighborTwoMirrored) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreNeighboringBuildingActorsConnected(const ABuildingSMActor* NeighborOne, const ABuildingSMActor* NeighborTwo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreGridIndicesValid(const FBuildingSupportCellIndex& GridIndices) const;
};

