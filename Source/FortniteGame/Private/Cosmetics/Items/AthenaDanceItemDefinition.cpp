#include "AthenaDanceItemDefinition.h"

UAthenaDanceItemDefinition::UAthenaDanceItemDefinition()
{
	ItemType = EFortItemType::AthenaDance;
	GameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Cosmetics.EmoteType.Dance")));
}