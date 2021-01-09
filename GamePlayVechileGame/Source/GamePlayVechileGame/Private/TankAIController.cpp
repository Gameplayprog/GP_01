// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "AimComponent.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	auto Tank = GetPawn();
	auto AimComp = Tank->FindComponentByClass<UAimComponent>();

	if (PlayerTank)
	{
		//TODO Move towards 
		MoveToActor(PlayerTank, AiRadius,true,true,true, DefaultNavigationFilterClass,true);

		//Aim Towards	
		AITank->AimAt(PlayerTank->GetActorLocation(), PlayerTank->ProjectileSpeed);
		
		AimComp->Fire();
	}

}

