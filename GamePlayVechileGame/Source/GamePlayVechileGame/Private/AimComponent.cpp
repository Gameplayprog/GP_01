// Fill out your copyright notice in the Description page of Project Settings.


#include "AimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"



// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UAimComponent::AimSetting(UTankBarrel* BarrelToSet, UTankTurret*TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimComponent::AimAt(FVector HitLocation, float ProjectileSpeed)
{
	if (!ensure(Barrel)) { return; }
	FVector OUTTossVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool AimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUTTossVelocity,
		StartLocation,
		HitLocation,
		ProjectileSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);


	if (AimSolution)
	{
		//Maths for the launch velcoity 
		auto AimDirection = OUTTossVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
		// Aim Solution not found
}
//Figure out where the barrel should be, considering where it is.
void UAimComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
	UE_LOG(LogTemp,Warning, TEXT("Im Here"))
	auto RotationOfBarrel = Barrel->GetForwardVector().Rotation();
	auto RotationOfAim = AimDirection.Rotation();
	auto DiffrenceInRotation = RotationOfAim - RotationOfBarrel;
	
	Barrel->Elvate(DiffrenceInRotation.Pitch); //TODO make varible
	if (FMath::Abs(DiffrenceInRotation.Yaw) < 180)
	{
		Turret->Spin(DiffrenceInRotation.Yaw);
	}
	else
	{
		Turret->Spin(-DiffrenceInRotation.Yaw);
	}
}

void UAimComponent::Fire()
{
	if (!ensure(Barrel && ProjectileBlueprint)) { return; }
	bool IsReloaded = (GetWorld()->GetRealTimeSeconds() - LastFireTime) > ReloadTimer;

	if (IsReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = GetWorld()->GetRealTimeSeconds();
	}
}



