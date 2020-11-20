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
ATank* AVechilePlayerController::GetControlledTank() const
{



	return Cast<ATank>(GetPawn());
}


