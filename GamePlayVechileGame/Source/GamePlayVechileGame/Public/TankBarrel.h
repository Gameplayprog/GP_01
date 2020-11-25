// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class GAMEPLAYVECHILEGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankBarrel();
	//- 1 is max down movement and +1 for up movement 
	void Elvate(float Relativespeed);
private:
	UPROPERTY(EditAnywhere, Category =  Setup)
	float DegreesesPerSecond = 20; 
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
};
