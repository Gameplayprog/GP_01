// Fill out your copyright notice in the Description page of Project Settings.


#include "TMovementComponent.h"
#include "TankTrack.h"


void UTMovementComponent::TrackSetting(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
void UTMovementComponent::IntenedMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->ThrottleSet(Throw);
	RightTrack->ThrottleSet(Throw);

	//TODO fix double speed 
}

void UTMovementComponent::IntenedSpinClockWise(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->ThrottleSet(Throw);
	RightTrack->ThrottleSet(-Throw);

	//TODO fix double speed 
}