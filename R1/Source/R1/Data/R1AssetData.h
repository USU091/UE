// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "R1AssetData.generated.h"


USTRUCT()
struct FAssetEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FName AssetName;

	//경로 설정
	UPROPERTY(EditDefaultsOnly)
	FSoftObjectPath AssetPath;

	UPROPERTY(EditDefaultsOnly)
	TArray<FName> AssetLabels;

};

USTRUCT()
struct FAssetSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FAssetEntry> AssetEntries;
};
/**
 * 
 */
UCLASS()
class R1_API UR1AssetData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual void PreSave(FObjectPreSaveContext ObjectSaveContext) override;

public:
	//우리가 원하는 에셋을 이름으로 Get해서 씀
	FSoftObjectPath GetAssetPathByName(const FName& AssetName);
	//label을 이용해서 가져올 수 도 있게끔 만듬
	const FAssetSet& GetAssetSetByLabel(const FName& Label);

private:

	UPROPERTY(EditDefaultsOnly)
	TMap<FName, FAssetSet> AssetGroupNameToSet;
	
	
	UPROPERTY()
	TMap<FName, FSoftObjectPath> AssetNameToPath;

	UPROPERTY()
	TMap<FName, FAssetSet> AssetLabelToSet;
};
