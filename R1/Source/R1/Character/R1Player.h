// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/R2Character.h"
#include "R1Player.generated.h"

DECLARE_DELEGATE(FUSU0);
//DECLARE_DELEGATE_OneParam(FUSU0, int);

DECLARE_MULTICAST_DELEGATE(FUSU0MulticastDelegate)

/**
 * 
 */
UCLASS()
class R1_API AR1Player : public AR2Character
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AR1Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UCameraComponent> Camera;
	
public:

	UFUNCTION()
	void TestFunc() {}

	FUSU0 Usu0Delegate;
	FUSU0MulticastDelegate MulticastDelegate;
};
