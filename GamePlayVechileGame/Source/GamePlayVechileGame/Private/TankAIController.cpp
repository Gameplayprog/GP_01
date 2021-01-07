// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "AimComponent.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	if (!ensure(PlayerTank && AITank)) { return; }
	//TODO Move towards 
	MoveToActor(PlayerTank, AiRadius, true, true, true, DefaultNavigationFilterClass, true);

	//Aim Towards	
	auto Aimingcomp = GetPawn()->FindComponentByClass<UAimComponent>();
	Aimingcomp->AimAt(PlayerTank->GetActorLocation());

	//AITank->Fire(); 
	

}