// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "UObject/ConstructorHelpers.h"
void UTankBarrel::Elvate(float Relativespeed) 
{
	//Clamp the speed so it doesnt go too fast 
	Relativespeed = FMath::Clamp<float>(Relativespeed, -1, 1);
	auto ChangeInElevation = Relativespeed * DegreesesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ChangeInElevation;
	//Putting a range on the elevation so the barrel doesnt exceed what we have set. 
	auto ClampedElevation =  FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation );

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));

}
//Fixing a issue where the barrel loses the mesh for the barrel when re Complied 
UTankBarrel::UTankBarrel()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelAsset(TEXT("/Game/Tank/tank_fbx_Barrel"));
	this->SetStaticMesh(BarrelAsset.Object);
	this->SetRelativeLocation(FVector::ZeroVector);
}