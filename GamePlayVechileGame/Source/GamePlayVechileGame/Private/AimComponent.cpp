// Fill out your copyright notice in the Description page of Project Settings.


#include "AimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"



// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAimComponent::barrelsetref(UTankBarrel* ToBeSetBarrel)
{
	if (!ToBeSetBarrel) { return; }
	Barrel = ToBeSetBarrel;
}

void UAimComponent::Turretsetref(UTankTurret * ToBeSetTurret)
{
	if (!ToBeSetTurret) { return; }
	Turret = ToBeSetTurret;
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
	if (!Barrel) { return; }
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
		auto TIme = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" %f : Aim Solution Found "), TIme);
	}
	else
	{
		auto TIme = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" %f : Aim Solution Not Found "), TIme);
	}
}
//Figure out where the barrel should be, considering where it is.
void UAimComponent::MoveBarrel(FVector AimDirection)
{
	auto RotationOfBarrel = Barrel->GetForwardVector().Rotation();
	auto RotationOfAim = AimDirection.Rotation();
	auto DiffrenceInRotation = RotationOfAim - RotationOfBarrel;
	
	Barrel->Elvate(DiffrenceInRotation.Pitch); //TODO make varible
	Turret->Spin(DiffrenceInRotation.Yaw);



}



