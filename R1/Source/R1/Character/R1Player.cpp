// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/R1Player.h"
#include "Character/R2Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"




AR1Player::AR1Player()
{

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	//Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	
	SpringArm->SetRelativeRotation(FRotator(-60, 0, 0));
	SpringArm->TargetArmLength = 800.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECC_Pawn, ECR_Ignore);
}

void AR1Player::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);


	////Delegate Test
	//// +=
	//Usu0Delegate.BindUObject(this, &ThisClass::TestFunc);

	////invoke
	//Usu0Delegate.Execute();	

	////-=
	//Usu0Delegate.Unbind();

	//auto h1 = MulticastDelegate.AddUObject(this, &ThisClass::TestFunc);
	//MulticastDelegate.AddUObject(this, &ThisClass::TestFunc);
	//MulticastDelegate.AddUObject(this, &ThisClass::TestFunc);
	//MulticastDelegate.AddUObject(this, &ThisClass::TestFunc);
	//MulticastDelegate.AddUObject(this, &ThisClass::TestFunc);
	//MulticastDelegate.Broadcast();
	//MulticastDelegate.Remove(h1);
	//MulticastDelegate.RemoveAll();

}

void AR1Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AR1Player::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("OnBeginOverlap"));

}
