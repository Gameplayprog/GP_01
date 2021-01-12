// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "UObject/ConstructorHelpers.h"
#include "SpawnWheel.h"
#include "SpringWheel.h"

void UTankTrack::ThrottleSet(float Throttle)
{
//TODO CLAMP 
	float CThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CThrottle);
}

void UTankTrack::DriveTrack(float CThrottle)
{
	auto ForceApplied = CThrottle * MaxDriveForce;
	auto Wheels = GetWheels();
	auto ForcePerwheel = ForceApplied / Wheels.Num();
	for (ASpringWheel* wheel : Wheels)
	{
		wheel->AddForce(ForcePerwheel);
	}
}

UTankTrack::UTankTrack()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TrackAsset(TEXT("/Game/Tank/tank_fbx_Track"));
	this->SetStaticMesh(TrackAsset.Object);
	this->SetRelativeLocation(FVector::ZeroVector);
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}

TArray<ASpringWheel*> UTankTrack::GetWheels()const
{
	TArray<ASpringWheel*> Result;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children)
	{
		auto SpawnChild = Cast<USpawnWheel>(Child);
		if (!SpawnChild)  continue;

		AActor* ChildBeenSpawned = SpawnChild->SpawnedActorGetter();
		auto Wheel = Cast<ASpringWheel>(ChildBeenSpawned);
		if (!Wheel) continue;
		Result.Add(Wheel);
	}
	return Result;
}



