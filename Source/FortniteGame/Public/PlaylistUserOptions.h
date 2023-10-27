// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttributeSet.h"
#include "FortniteGame.h"
#include "PlaylistUserOptions.generated.h"

UCLASS(Abstract)
class FORTNITEGAME_API UPlaylistUserOptionBase : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UObject> OptionScope;

	UPROPERTY(EditAnywhere)
	FString OptionKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText OptionDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText OptionDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* OptionMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bCanHaveNoOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EUFortMatchmakingKnobsDataSource  MenuListType;  
};

USTRUCT(BlueprintType)
struct FPlaylistOptionValue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString OptionValueName;
};

USTRUCT(BlueprintType)
struct FPlaylistOptionColorValue : public FPlaylistOptionValue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor Value;
};

USTRUCT(BlueprintType)
struct FPlaylistOptionIntValue : public FPlaylistOptionValue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Value;
};

USTRUCT(BlueprintType)
struct FPlaylistOptionFloatValue : public FPlaylistOptionValue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FScalableFloat Value;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionFloatEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FPlaylistOptionFloatValue> OptionValues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 DefaultValueIndex;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FPlaylistOptionValue> OptionValues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 DefaultValueIndex;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionIntEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FPlaylistOptionIntValue> OptionValues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 DefaultValueIndex;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionColorEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FPlaylistOptionColorValue> OptionValues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 DefaultValueIndex;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionFloatRange : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Min;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Max;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefaultValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float IncrementValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText UnitName;  
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionIntRange : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Min;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Max;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 DefaultValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 IncrementValue;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionBool : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bDefaultValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText OptionOnText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText OptionOffText;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionString : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString DefaultValue;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptionMusicTrackDataTable : public UPlaylistUserOptionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* DataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString DefaultValue;
};

UCLASS()
class FORTNITEGAME_API UPlaylistUserOptions : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UPlaylistUserOptionBase*> Options;
};
