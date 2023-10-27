// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "FortniteGame.h"
#include "Sound/SoundBase.h"
#include "FortFeedbackBank.h"
#include "FortConversation.generated.h"

USTRUCT(BlueprintType)
struct FFortSentenceAudio
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<USoundBase> Audio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FFortFeedbackHandle Handle;
};

USTRUCT(BlueprintType)
struct FFortConversationSentence
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FFortSentenceAudio SpeechAudio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText SpeechText;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> TalkingHeadTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText TalkingHeadTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<class UAnimMontage> AnimMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PostSentenceDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DisplayDuration;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortConversation : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TArray<FFortConversationSentence> Sentences;
};
