// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TMovementComponent.generated.h"

class UTankTrack;
/**
 * 
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
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
