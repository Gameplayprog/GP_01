// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class GAMEPLAYVECHILEGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	//-1 and +1 max speeds 
	void Spin(float Relativespeed);

	UTankTurret();
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float SpinSpeed = 25;

 };
