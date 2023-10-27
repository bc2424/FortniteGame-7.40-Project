#include "AthenaSprayItemDefinition.h"

UAthenaSprayItemDefinition::UAthenaSprayItemDefinition()
{
	ItemType = EFortItemType::AthenaDance;
	GameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Cosmetics.EmoteType.Spray")));
	GameplayTags.RemoveTag(FGameplayTag::RequestGameplayTag(FName("Cosmetics.EmoteType.Dance")));
}