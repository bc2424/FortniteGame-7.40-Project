#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "AthenaEmojiItemDefinition.generated.h"

UCLASS()
class FORTNITEGAME_API UAthenaEmojiItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()
public:
	UAthenaEmojiItemDefinition();
	UPROPERTY(EditAnywhere, Category = "Gameplay Tags")
	FGameplayTag EmojiGameplayCueTag;

	UPROPERTY(EditAnywhere, Category = "Emote")
	TSoftObjectPtr<UAnimMontage> PreviewAnimation;

	UPROPERTY(EditAnywhere, Category = "Texture")
	TSoftObjectPtr<UTexture2D> SpriteSheet;

	UPROPERTY(EditAnywhere, Category = "Texture")
	FIntPoint SheetDimensions = FIntPoint(1, 1);

	UPROPERTY(EditAnywhere, Category = "Texture")
	int FrameIndex;

	UPROPERTY(EditAnywhere, Category = "Texture")
	int FrameCount = 1;

	UPROPERTY(EditAnywhere, Category = "Material")
	UMaterialInterface* BaseMaterial;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	FVector IconSize;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	FLinearColor InitialColor;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	FVector InitialLocation;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	FVector InitialVelocity;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	float LifetimeIntroSeconds;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	float LifetimeMidSeconds;

	UPROPERTY(EditAnywhere, Category = "Particle System")
	float LifetimeOutroSeconds;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* GeneratedMaterial;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaDance", GetFName());
	}
};
