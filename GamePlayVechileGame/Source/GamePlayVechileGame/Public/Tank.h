// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

///Forward declarations
class UTankBarrel; 
class UAimComponent;
class UTankTurret;
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

	


	UPROPERTY(EditAnywhere, Category = Firing)
	float ProjectileSpeed = 5000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UAimComponent* Tankaimingcomponent = nullptr;


private:	
	// Sets default values for this pawn's properties
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Barrel for spawning projectile
	UTankBarrel* Barrel = nullptr;

	float ReloadTimer = 3; 
	float LastFireTime = 0;


};
