// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"
#include "UObject/ConstructorHelpers.h"

void UTankTurret::Spin(float Relativespeed)
{
	Relativespeed = FMath::Clamp<float>(Relativespeed, -1, 1);
	auto ChangeInRotation = Relativespeed * SpinSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + ChangeInRotation;
	//Putting a range on the elevation so the barrel doesnt exceed what we have set. 

	SetRelativeRotation(FRotator(0, NewRotation, 0));

}

