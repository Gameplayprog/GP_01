// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "AimComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"

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

	auto SidewaysSpeed = FVector::DotProduct(GetActorRightVector(), GetVelocity());

	auto Correction = - SidewaysSpeed / DeltaTime * GetActorRightVector();

	auto root = Cast<UStaticMeshComponent>(GetRootComponent());
	auto force = (root->GetMass() * Correction);
	root->AddForce(force);

}




