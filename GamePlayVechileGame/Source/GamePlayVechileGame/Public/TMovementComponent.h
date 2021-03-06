// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TMovementComponent.generated.h"

class UTankTrack;
/**
 * Drives the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEPLAYVECHILEGAME_API UTMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntenedMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void TrackSetting(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntenedSpinClockWise(float Throw);

private:
	//Pointers for 2 unassinged TankTracks
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
	//Called when AI controller MoveToActor 
	virtual void RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) override;
};
