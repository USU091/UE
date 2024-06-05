// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "R1PlayerController.generated.h"

struct FInputActionValue;

/**
 * 
 */
UCLASS()
class R1_API AR1PlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	AR1PlayerController(const FObjectInitializer& ObjectInitializer);

private:
	//Pawn도 Actor를 상속받았기 때문에 BeginPlay(), SetupInputComponent() 를 override해 올 것임

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void Input_Test(const FInputActionValue& InputValue);
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Turn(const FInputActionValue& InputValue);

protected:
	UPROPERTY(Category=Input, EditAnywhere)
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(Category = Input, EditAnywhere)
	TObjectPtr<class UInputAction> TestAction;

	UPROPERTY(Category = Input, EditAnywhere)
	TObjectPtr<class UInputAction> MoveAction;


	UPROPERTY(Category = Input, EditAnywhere)
	TObjectPtr<class UInputAction> TurnAction;




};
