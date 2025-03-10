﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/R2Character.h"
#include "R1Monster.generated.h"

/**
 * 
 */
UCLASS()
class R1_API AR1Monster : public AR2Character
{
	GENERATED_BODY()
public:
	AR1Monster();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
