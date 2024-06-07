// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "R1AssetManager.generated.h"

/**
 * 
 */

//Resources Manager의 역할. Asset을 관리해주는 역할. 초반에 Asset을 읽어서 들고있음
UCLASS()
class R1_API UR1AssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	//생성자
	UR1AssetManager();

	//싱글톤으로 만들기 위한 함수 생성
	static UR1AssetManager& Get();
	

	//TODO : load한 모든 에셋들을 가져와야됨
};
