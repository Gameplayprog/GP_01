// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "AimComponent.h"
#include "Projectile.h"
#include "TMovementComponent.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}



void ATank::AimAt(FVector HitLocation ,float ProjectileSpeed) {
	if (!Tankaimingcomponent) { return; }
	Tankaimingcomponent->AimAt(HitLocation, ProjectileSpeed);
}

void ATank::Fire()
{
	bool IsReloaded = (GetWorld()->GetRealTimeSeconds() - LastFireTime) > ReloadTimer;
	
	if (Barrel  && IsReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = GetWorld()->GetRealTimeSeconds();
	}
}


