#include "MissionTypes.h"

void UFortMissionFailedParams::SetParams(AFortMission* _FailedMission, UFortMissionFailedParams*& ThisParam) {
}

void UFortMissionFailedParams::BreakParams(AFortMission*& _FailedMission) {
}

UFortMissionFailedParams::UFortMissionFailedParams() {
	this->FailedMission = NULL;
}

void UFortItemDroppedParams::SetParams(const UFortWorldItemDefinition* _DroppedItemDefinition, AFortPlayerController* _DroppedBy, int32 _AmountCollected, UFortItemDroppedParams*& ThisParam) {
}

void UFortItemDroppedParams::BreakParams(UFortWorldItemDefinition*& _DroppedItemDefinition, AFortPlayerController*& _DroppedBy, int32& _AmountCollected) {
}

UFortItemDroppedParams::UFortItemDroppedParams() {
	this->DroppedItemDefinition = NULL;
	this->DroppedBy = NULL;
	this->AmountDropped = 0;
}
