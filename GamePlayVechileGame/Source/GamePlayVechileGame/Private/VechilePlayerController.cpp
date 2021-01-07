// Fill out your copyright notice in the Description page of Project Settings.


#include "VechilePlayerController.h"
#include "AimComponent.h"


void AVechilePlayerController::BeginPlay()
{
	//calling the default code before new code
	Super::BeginPlay();
	auto Aimingcomp = GetPawn()->FindComponentByClass<UAimComponent>();
	if (!ensure(Aimingcomp)) { return; }
	AimCompFound(Aimingcomp);
}

void AVechilePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}
void AVechilePlayerController::AimTowardsCrosshair()
{
	auto Aimingcomp = GetPawn()->FindComponentByClass<UAimComponent>();
	if (!ensure(Aimingcomp)) { return; }

	FVector HitLocation; //Outparameter
	if (GetSightRayHitLocation(HitLocation)) // has a side effect, is going to line trace 
	{
		Aimingcomp->AimAt(HitLocation);
	}
}
//get world location of line trace, true only if hits landscape 
bool AVechilePlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find Crosshair in Viewport Coords
	int32 SizeX, SizeY;
	GetViewportSize(SizeX, SizeY);
	auto ScreenLocatation = FVector2D(SizeX * crosshairXLocation, SizeY * crosshairYLocation);
	FVector LookDirection;
	if (GetDirectionOFlook(ScreenLocatation, LookDirection))
	{
		GetVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}
bool AVechilePlayerController::GetVectorHitLocation(FVector LookDirection, FVector HitLocation) const
{
	FHitResult TraceHit;
	auto StartTrace = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartTrace + (LookDirection * TraceRange);
	auto Aimingcomp = GetPawn()->FindComponentByClass<UAimComponent>();
	if (GetWorld()->LineTraceSingleByChannel(TraceHit, StartTrace, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = TraceHit.Location;
		Aimingcomp->AimAt(HitLocation);
		return true;
	}
	HitLocation = FVector(0);
	return false;

}
bool AVechilePlayerController::GetDirectionOFlook(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation; // to be removed
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);
}