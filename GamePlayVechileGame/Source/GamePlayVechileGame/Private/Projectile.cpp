// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collsion = CreateDefaultSubobject<UStaticMeshComponent>(FName(" Collsion"));
	SetRootComponent(Collsion);
	Collsion->SetNotifyRigidBodyCollision(true);
	Collsion->SetVisibility(false);
	//Setting up the Particle with sensiable defaults
	MuzzeleBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName(" Muzzle Blast"));
	MuzzeleBlast->AttachTo(RootComponent);

	TankProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName(" Tank Projectile Movement Component"));
	TankProjectileMovementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AProjectile::LaunchProjectile(float Speed)
{
	
	TankProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	TankProjectileMovementComponent->Activate();
}

