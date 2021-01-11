// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "UObject/ConstructorHelpers.h"

void UTankTrack::ThrottleSet(float Throttle)
{
//TODO CLAMP 
	CThrottle = FMath::Clamp<float>(CThrottle + Throttle, -1, 1);

}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CThrottle * MaxDriveForce;
	auto ForceLocation = GetComponentLocation();
	//Unable to apply force to scenecomponenet so applied to primitive componenet
	auto Tankroot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	Tankroot->AddForceAtLocation(ForceApplied, ForceLocation);
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

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}
void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	SideWaysForce();
	CThrottle = 0;
}

void UTankTrack::SideWaysForce()
{
	auto SidewaysSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto Correction = -SidewaysSpeed / DeltaTime * GetRightVector();
	auto root = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto force = (root->GetMass() * Correction);
	root->AddForce(force);
}


