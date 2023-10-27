#include "AthenaEmojiItemDefinition.h"

UAthenaEmojiItemDefinition::UAthenaEmojiItemDefinition()
{
	ItemType = EFortItemType::AthenaDance;
	bMovingEmote = true;
	GameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Cosmetics.EmoteType.Emoji")));
	GameplayTags.RemoveTag(FGameplayTag::RequestGameplayTag(FName("Cosmetics.EmoteType.Dance")));
	DisplayName = FText::FromString("Emoticon");
}