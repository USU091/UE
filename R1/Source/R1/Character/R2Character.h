﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/R1HighlightInterface.h"
#include "R2Character.generated.h"

UCLASS()
class R1_API AR2Character : public ACharacter, public IR1HighlightInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AR2Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Highlight() override;
	virtual void UnHighlight() override;

protected:

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;


};
