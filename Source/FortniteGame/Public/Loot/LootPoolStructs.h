// All fortnites reserved AllyJax

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortniteGame.h"
#include "LootPoolStructs.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FFortLootTierData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       TierGroup;                                                // 0x0008(0x0008) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              Weight;                                                   // 0x0010(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ELootQuotaLevel                       QuotaLevel;                                               // 0x0014(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)                                    // 0x0015(0x0003) MISSED OFFSET
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                LootTier;                                                 // 0x0018(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                MinWorldLevel;                                            // 0x001C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                MaxWorldLevel;                                            // 0x0020(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)                                   // 0x0024(0x0004) MISSED OFFSET
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString                                     StreakBreakerCurrency;                                    // 0x0028(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                StreakBreakerPointsMin;                                   // 0x0038(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                StreakBreakerPointsMax;                                   // 0x003C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                StreakBreakerPointsSpend;                                 // 0x0040(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)                                      // 0x0044(0x0004) MISSED OFFSET
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       LootPackage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       LootPreviewPackage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              NumLootPackageDrops;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int>                                        LootPackageCategoryWeightArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int>                                        LootPackageCategoryMinArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int>                                        LootPackageCategoryMaxArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool                                      bAllowBonusLootDrops;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString                                     Annotation;
};

USTRUCT(BlueprintType)
struct FFortLootPackageData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       LootPackageID;                                            // 0x0008(0x0008) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              Weight;                                                   // 0x0010(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                Count;                                                    // 0x0014(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                LootPackageCategory;                                      // 0x0018(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)                                  // 0x001C(0x0004) MISSED OFFSET
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       RequiredTag;                                              // 0x0020(0x0008) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString                                     LootPackageCall;                                          // 0x0028(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TAssetPtr<class UFortItemDefinition>               ItemDefinition;                                           // 0x0038(0x0020) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString                                     PersistentLevel;                                          // 0x0058(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                MinWorldLevel;                                            // 0x0068(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                MaxWorldLevel;                                            // 0x006C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool                                      bAllowBonusDrops;                                     // 0x0070(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString                                     Annotation;
};




class FORTNITEGAME_API LootPoolStructs
{
};
