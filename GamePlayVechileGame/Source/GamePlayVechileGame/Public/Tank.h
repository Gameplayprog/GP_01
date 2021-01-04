// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

///Forward declarations
class UTankBarrel; 
class UAimComponent;
class UTankTurret;
class UTMovementComponent;
class AProjectile;

UCLASS()
class GAMEPLAYVECHILEGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation, float ProjectileSpeed);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void ToBeSetTurretRef(UTankTurret* ToSetTurret);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void ToBeSetBarrelRef(UTankBarrel* ToSetBarrel);

	UFUNCTION(BlueprintCallable)
	void Fire();

	


	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ProjectileSpeed = 7500;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UAimComponent* Tankaimingcomponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTMovementComponent* TMovementcomponent = nullptr;


private:	
	// Sets default values for this pawn's properties
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Barrel for spawning projectile
	UTankBarrel* Barrel = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimer = 3; 
	float LastFireTime = 0;


};
