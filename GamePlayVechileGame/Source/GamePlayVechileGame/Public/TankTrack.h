// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank trac used for setting driving force, and apply force
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class GAMEPLAYVECHILEGAME_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = input)
	void ThrottleSet(float Throttle);
	
	// max force per track in NewTons
	UPROPERTY(EditDefaultsOnly)
	float MaxDriveForce = 400000; 

	UTankTrack();
};

