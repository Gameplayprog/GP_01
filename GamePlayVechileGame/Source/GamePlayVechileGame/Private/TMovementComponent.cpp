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
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->ThrottleSet(Throw);
	RightTrack->ThrottleSet(Throw);

	//TODO fix double speed 
}

void UTMovementComponent::IntenedSpinClockWise(float Throw)
{
	if (!ensure (LeftTrack && RightTrack)) { return; }
	LeftTrack->ThrottleSet(Throw);
	RightTrack->ThrottleSet(-Throw);

	//TODO fix double speed 
}

void UTMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntenedMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntenedSpinClockWise(RightThrow);

}
