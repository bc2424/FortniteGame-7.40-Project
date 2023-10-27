#include "AthenaDanceItemDefinition.h"

FText UAthenaDanceItemDefinition::GetChatTriggerCommandName() const {
    return FText::GetEmpty();
}

UAthenaDanceItemDefinition::UAthenaDanceItemDefinition() {
    this->bMovingEmote = false;
    this->bMoveForwardOnly = false;
    this->WalkForwardSpeed = 300.00f;
}

