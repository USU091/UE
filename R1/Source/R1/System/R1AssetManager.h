// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "R1LogChannels.h"
#include "CoreMinimal.h"
#include "Data/R1AssetData.h"
#include "Engine/AssetManager.h"
#include "R1AssetManager.generated.h"

/**
 * 
 */
class UR1AssetData;

DECLARE_DELEGATE_TwoParams(FAsyncLoadCompletedDelegate, const FName& /*AssetName or Label*/, UObject* /*LoadedAsset*/);
//Resources Manager의 역할. Asset을 관리해주는 역할. 초반에 Asset을 읽어서 들고있음
UCLASS()
class R1_API UR1AssetManager : public UAssetManager
{
	GENERATED_BODY()
	FAsyncLoadCompletedDelegate test;

public:

	//생성자
	UR1AssetManager();

	//싱글톤으로 만들기 위한 함수 생성
	static UR1AssetManager& Get();
	
public:
	static void Initialize();
	//TODO : load한 모든 에셋들을 가져와야됨

	template<typename AssetType>
	static AssetType* GetAssetByName(const FName& AssetName);


	static void LoadSyncByPath(const FSoftObjectPath& AssetPath);
	static void LoadSyncByName(const FName& AssetName);
	static void LoadSyncByLabel(const FName& Label);

	//비동기방식의 함수
	static void LoadAsyncByPath(const FSoftObjectPath& AssetPath, FAsyncLoadCompletedDelegate CompletedDelegate = FAsyncLoadCompletedDelegate());
	static void LoadAsyncByName(const FSoftObjectPath& AssetName, FAsyncLoadCompletedDelegate CompletedDelegate = FAsyncLoadCompletedDelegate());

	//릴리즈 시리즈
	static void ReleaseByPath(const FSoftObjectPath& AssetPath);
	static void ReleaseByName(const FName& AssetName);
	static void ReleaseByLabel(const FName& Label);
	static void ReleaseAll();

private:
	void LoadPreloadAssets();
	void AddLoadedAsset(const FName& AssetName, const UObject* Asset);


private:
	UPROPERTY()
	TObjectPtr<UR1AssetData> LoadedAssetData;
	
	UPROPERTY()
	TMap<FName, TObjectPtr<const UObject>> NameToLoadedAsset;

};

template<typename AssetType>
inline AssetType* UR1AssetManager::GetAssetByName(const FName& AssetName)
{
	UR1AssetData* AssetData = Get().LoadedAssetData;
	check(AssetData);

	AssetType* LoadedAsset = nullptr;
	const FSoftObjectPath& AssetPath = AssetData->GetAssetPathByName(AssetName);
	if (AssetPath.IsValid())
	{
		LoadedAsset = Cast<AssetType>(AssetPath.ResolveObject());
		if (LoadedAsset == nullptr)
		{
			UE_LOG(LogR1, Warning, TEXT("Attempted sync loading because asset hadn't loaded yes [%s]"), *AssetPath.ToString());
			LoadedAsset = Cast<AssetType>(AssetPath.TryLoad());
		}
	}
	return LoadedAsset;
}
