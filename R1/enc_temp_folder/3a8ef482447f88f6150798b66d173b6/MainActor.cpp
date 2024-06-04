// Fill out your copyright notice in the Description page of Project Settings.


#include "MainActor.h"
#include "R1Actor.h"

// Sets default values
AMainActor::AMainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FClassFinder<AR1Actor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/USU0/BP_R1Actor.BP_R1Actor_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}
}

// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();
	//Spawn
	FVector Location(0, 0, 0);
	FRotator Rotation(0, 0, 0);
	//AR1Actor* Actor = GetWorld()->SpawnActor<AR1Actor>(Location, Rotation);
	//Actor = GetWorld()->SpawnActor<AR1Actor>(Location, Rotation);
	
	//#C++ 4대 캐스팅
	// static
	// dynamic
	// reinterpret_cast
	// const


	//이 경우는 dynamic Cast를 진행해야 함, 언리얼에서는 아래로 대체
	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));
	
	//Actor->SetLifeSpan(3.0f);
	//GetWorld()->DestroyActor(Actor);
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

