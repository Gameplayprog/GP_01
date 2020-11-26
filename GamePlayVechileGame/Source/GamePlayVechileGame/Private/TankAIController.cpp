// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO Move towards 

		//Aim Towards 
		AITank->AimAt(PlayerTank->GetActorLocation(), PlayerTank->ProjectileSpeed);

		AITank->Fire(); 
	}

}

