// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Actor.generated.h"		//generated.h 파일은 항상 include 마지막에 선언해줘야됨.순서.

class UR1Object;	//클래스 전방선언해줌


UCLASS()
class R1_API AR1Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AR1Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UR1Object* Obj1;

	UPROPERTY()
	UR1Object* Obj2;
};
