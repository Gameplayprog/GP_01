// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "AimComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Tankaimingcomponent = CreateDefaultSubobject<UAimComponent>(FName("Aim component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation ,float ProjectileSpeed) {
	Tankaimingcomponent->AimAt(HitLocation, ProjectileSpeed);
}

void ATank::ToBeSetBarrelRef(UTankBarrel* ToSetBarrel)
{
	Tankaimingcomponent->barrelsetref(ToSetBarrel);
	Barrel = ToSetBarrel;
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
void ATank::ToBeSetTurretRef(UTankTurret* ToSetTurret)
{
	Tankaimingcomponent->Turretsetref(ToSetTurret);
}


