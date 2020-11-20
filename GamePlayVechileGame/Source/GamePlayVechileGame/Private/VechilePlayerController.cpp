// Fill out your copyright notice in the Description page of Project Settings.


#include "VechilePlayerController.h"





void AVechilePlayerController::BeginPlay()
{
	//calling the default code before new code
	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller Not Possing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller possing %s"), *(ControlledTank->GetName()));
	}
}

void AVechilePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	

}

ATank* AVechilePlayerController::GetControlledTank() const
{



	return Cast<ATank>(GetPawn());
}

void AVechilePlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}
	FVector HitLocation; //Outparameter
	if (GetSightRayHitLocation(HitLocation)) // has a side effect, is going to line trace 
	{
		//UE_LOG(LogTemp, Warning, TEXT("look direction: %s"), *HitLocation.ToString());
				// TODO tell controlled tank to aim at this point 
	}
}
//get world location of line trace, true only if hits landscape 
bool AVechilePlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find Crosshair in Viewport Coords
	int32 SizeX, SizeY;
	GetViewportSize(SizeX, SizeY);
	auto ScreenLocatation = FVector2D(SizeX * crosshairXLocation, SizeY * crosshairYLocation);
	FVector CameraLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocatation.X, ScreenLocatation.Y, CameraLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("look direction: %s"), *WorldDirection.ToString());
	}
	return true;
}




