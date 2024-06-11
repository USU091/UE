// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/R2Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AR2Character::AR2Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void AR2Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AR2Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

