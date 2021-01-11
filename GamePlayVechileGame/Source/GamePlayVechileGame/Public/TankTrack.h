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
	float MaxDriveForce = 40000000; 

private:
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	void SideWaysForce();
	UTankTrack();
	void DriveTrack();
	float CThrottle = 0;
};

