// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	//ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/USU0/SM_ChamferCube.SM_ChamferCube'"));
	//if (FindMesh.Succeeded())
	//{
	//	Box->SetStaticMesh(FindMesh.Object);
	//}

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	Body->SetRelativeScale3D(FVector(4, 2, 0.5));

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body);
	Head->SetRelativeLocationAndRotation(FVector(63, 11.5, 0), FRotator(0,0,0));		//Frotator =>y,z,x순으로
	Head->SetRelativeScale3D(FVector(0.4, 0.3, 3.5));

	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body);
	Wing->SetRelativeLocationAndRotation(FVector(0,40,0), FRotator(0,0,0));
	Wing->SetRelativeScale3D(FVector(0.1, 8.3, 0.5));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/USU0/SM_ChamferCube.SM_ChamferCube'"));
	if (FindMesh.Succeeded())
	{
		Body->SetStaticMesh(FindMesh.Object);
		Head->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
	}

}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();

	//Target = UGameplayStatics::GetActorOfClass(GetWorld(), AR1Actor::StaticClass());
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("USU0"), Actors);
	if (Actors.Num() > 0)
	{
		Target = Actors[0];
	}
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target != nullptr)
	{
		//이동 거리 = 이동 속력 * 시간
		float Speed = 50.0f;
		float Distance = DeltaTime * Speed;		//매 프레임 이동하는 거리가 구해짐

		FVector Location = GetActorLocation();	//현재 위치

		FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
		DirectionVector.Normalize();

		//FVector NewLoacation = Location + DirectionVector * Distance;
		//SetActorLocation(NewLoacation);

		AddActorWorldOffset(DirectionVector * Distance);		//방향벡터만 구함
	}


}

