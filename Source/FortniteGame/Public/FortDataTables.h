// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTags.h"
#include "Quests/FortQuestItemDefinition.h"
#include "ChallengeBundles/FortChallengeBundleItemDefinition.h"
#include "FortDataTables.generated.h"

USTRUCT()
struct FORTNITEGAME_API FTransmogSacrifice : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		int TransmogSacrificePoints;
};

USTRUCT()
struct FORTNITEGAME_API FFortLootLevelData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	 FName Category;
	
	UPROPERTY(EditAnywhere)
	int LootLevel;

	UPROPERTY(EditAnywhere)
	int MinItemLevel;

	UPROPERTY(EditAnywhere)
	int MaxItemLevel;                                     
};

USTRUCT()
struct FGlyphRewardInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	 UFortChallengeBundleItemDefinition* BundleDef;

	UPROPERTY(EditAnywhere)
	 UFortQuestItemDefinition* QuestDef; 
};

USTRUCT()
struct FORTNITEGAME_API FAthenaSeasonalXPCurveEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int Level;
	
	UPROPERTY(EditAnywhere)
	int XpToNextLevel;

	UPROPERTY(EditAnywhere)
	int XpTotal;                                           
};


USTRUCT()
struct FCosmeticSetDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere)
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere)
	FText DisplayName;

	UPROPERTY(EditAnywhere)
	FText Description;
};


USTRUCT()
struct FCosmeticMarkupTagDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere)
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere)
	FText DisplayName;

	UPROPERTY(EditAnywhere)
	FText HelpText;
};

USTRUCT()
struct FCosmeticFilterTagDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	 TArray<FText> SearchQueries;
};

USTRUCT()
struct FHomebaseBannerCategoryData : public FTableRowBase 
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FText CategoryDisplayName; 

	UPROPERTY(EditAnywhere)
	int SortPriority;

};
USTRUCT()
struct FHomebaseBannerColor 
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere)
	FLinearColor SecondaryColor;
};

USTRUCT()
struct FHomebaseBannerColorData : public FTableRowBase 
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FName ColorKeyName; 

	UPROPERTY(EditAnywhere)
	 FName CategoryRowName; 

	UPROPERTY(EditAnywhere)
	int SubCategoryGroup;

};

UCLASS()
class UFortHomebaseBannerColorMap : public UDataAsset 
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TMap<FName, FHomebaseBannerColor> ColorMap;
};

USTRUCT()
struct FORTNITEGAME_API FFortPawnStats : public FTableRowBase
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		float                                              MaximumHealth;

	UPROPERTY(EditAnywhere)
		float                                              SpeedWalk;

	UPROPERTY(EditAnywhere)
		float                                              SpeedRun;

	UPROPERTY(EditAnywhere)
		float                                              SpeedSprint;

	UPROPERTY(EditAnywhere)
		float                                              SpeedCrouchedRun;

	UPROPERTY(EditAnywhere)
		float                                              SpeedCrouchedSprint;

	UPROPERTY(EditAnywhere)
		float                                              SpeedBackwardsMultiplier;

	UPROPERTY(EditAnywhere)
		float                                              SpeedDBNO;

	UPROPERTY(EditAnywhere)
		float                                              AccelerationStrafeMultiplierSprint;

	UPROPERTY(EditAnywhere)
		class UCurveTable* FallingDamageTable;

	UPROPERTY(EditAnywhere)
		FName                                       FallingDamageTableRow;

	UPROPERTY(EditAnywhere)
		float                                              HealthRegenRate;

	UPROPERTY(EditAnywhere)
		float                                              HealthRegenDelay;

	UPROPERTY(EditAnywhere)
		float                                              HealthRegenThreshold;

	UPROPERTY(EditAnywhere)
		float                                              MaxShield;

	UPROPERTY(EditAnywhere)
		float                                              ShieldRegenRate;

	UPROPERTY(EditAnywhere)
		float                                              ShieldRegenDelay;

	UPROPERTY(EditAnywhere)
		float                                              ShieldRegenThreshold;

	UPROPERTY(EditAnywhere)
		float                                              MaxControlResistance;

	UPROPERTY(EditAnywhere)
		float                                              ControlResistanceRegenRate;

	UPROPERTY(EditAnywhere)
		float                                              ControlResistanceRegenDelay;

	UPROPERTY(EditAnywhere)
		float                                              KnockbackMultiplier;

	UPROPERTY(EditAnywhere)
		float                                              KnockbackThreshold;
};

USTRUCT()
struct FORTNITEGAME_API FFortPlayerPawnStats : public FFortPawnStats
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		float MaxJumpTime;

	UPROPERTY(EditAnywhere)
		float MaxStamina;

	UPROPERTY(EditAnywhere)
		float StaminaRegenRate;

	UPROPERTY(EditAnywhere)
		float StaminaRegenDelay;

	UPROPERTY(EditAnywhere)
		float SprintingStaminaExpenditureRate;
};