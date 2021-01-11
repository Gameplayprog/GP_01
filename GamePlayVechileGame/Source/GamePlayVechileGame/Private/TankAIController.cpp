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
		
		if (AimComp->GetAimingState() == EAimingStates::Locked)
		{
			AimComp->Fire();
		}
	}

}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto Tank = Cast<ATank>(InPawn);
		if (!ensure(Tank)) { return; }
		Tank->Death.AddUniqueDynamic(this, &ATankAIController::DelegateMethod);
	}
}

void ATankAIController::DelegateMethod()
{

}

