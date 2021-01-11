// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Projectile.generated.h"

class UTankProjectileMovementComponent;
UCLASS()
class GAMEPLAYVECHILEGAME_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LaunchProjectile(float Speed);
private:
	UProjectileMovementComponent* TankProjectileMovementComponent = nullptr;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Collsion = nullptr;
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* MuzzeleBlast = nullptr;
};
