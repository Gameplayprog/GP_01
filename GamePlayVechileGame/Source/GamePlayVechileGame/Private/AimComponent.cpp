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

bool UAimComponent::IsAiming()
{
	auto BarrelVec = Barrel->GetForwardVector();
	
	
	return !BarrelVec.Equals(AimDirection, 0.01);
}

// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	LastFireTime = GetWorld()->GetRealTimeSeconds();
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (bool IsReloaded = (GetWorld()->GetRealTimeSeconds() - LastFireTime) < ReloadTimer)
	{
		UE_LOG(LogTemp, Warning, TEXT(""))
		AimingState = EAimingStates::Reloading;
	}
	else if (IsAiming())
	{
		AimingState = EAimingStates::Aiming;
	}
	else
	{
		AimingState = EAimingStates::Locked;
	}
}
EAimingStates UAimComponent::GetAimingState() const
{
	return AimingState;
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
		AimDirection = OUTTossVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
		// Aim Solution not found
}
//Figure out where the barrel should be, considering where it is.
void UAimComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
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
	

	if (AimingState != EAimingStates::Reloading)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = GetWorld()->GetRealTimeSeconds();
	}
}



