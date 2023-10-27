#include "BuildingPropBigHealthMovable.h"

ABuildingPropBigHealthMovable::ABuildingPropBigHealthMovable()
{
	this->StaticMeshComponent->Mobility = EComponentMobility::Movable;
}