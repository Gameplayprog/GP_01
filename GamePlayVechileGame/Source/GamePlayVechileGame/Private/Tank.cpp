// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "AimComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"

float ATank::HealthGetter() const
{
	//casting ints to floats for hp %
	return (float)Chealth / (float)Health;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	auto TankName = GetName();
}

void ATank::BeginPlay()
{
	Super::BeginPlay();//Needed for Beginplay to run in BP
	auto TankName = GetName();

	Tankaimingcomponent = FindComponentByClass<UAimComponent>();
}



void ATank::AimAt(FVector HitLocation ,float ProjectileSpeed) {
	if (!ensure (Tankaimingcomponent)) { return; }
	Tankaimingcomponent->AimAt(HitLocation, ProjectileSpeed);
}
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 Damagepoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToTake = FMath::Clamp(Damagepoints, 0, Health);

	Chealth -= DamageToTake;
	if (Chealth <= 0)
	{
		Death.Broadcast();
	}
	return DamageToTake;
}






