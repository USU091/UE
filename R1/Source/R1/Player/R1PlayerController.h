// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "R1PlayerController.generated.h"

struct FInputActionValue;
class UNiagaraSystem;

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

	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();



private:
	//void Input_SetDestination(const FInputActionValue& InputValue);

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UNiagaraSystem> FXCursor;

private:

	FVector CachedDestination;
	float FollowTime;	// For how long it has been pressed
};
