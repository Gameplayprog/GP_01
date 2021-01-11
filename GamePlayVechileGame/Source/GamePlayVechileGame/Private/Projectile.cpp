// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collsion = CreateDefaultSubobject<UStaticMeshComponent>(FName(" Collsion"));
	SetRootComponent(Collsion);
	Collsion->SetNotifyRigidBodyCollision(true);
	Collsion->SetVisibility(false);
	//Setting up the Particles for Muzzle effect
	MuzzeleBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName(" Muzzle Blast"));
	MuzzeleBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Setting up the Particles for impact effect
	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName(" Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;
	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion force"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TankProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName(" Tank Projectile Movement Component"));
	TankProjectileMovementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	Collsion->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
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

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	MuzzeleBlast->Deactivate();
	ImpactBlast->Activate();
	ExplosionForce->FireImpulse();
	SetRootComponent(ImpactBlast);
	Collsion->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage(this, AppliedDamage, GetActorLocation(),ExplosionForce->Radius,UDamageType::StaticClass(),TArray<AActor*>());//damage all\\

	//outparameter
	FTimerHandle timer ;
	GetWorld()->GetTimerManager().SetTimer(timer,this,&AProjectile::OnTimerExpire,DestroyDelay,false);
}
void AProjectile::OnTimerExpire()
{
	Destroy();
}

