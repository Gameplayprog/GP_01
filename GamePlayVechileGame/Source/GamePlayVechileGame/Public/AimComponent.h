// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "AimComponent.generated.h"

// enums 
UENUM()
enum class EAimingStates:uint8
{
	Reloading,
	Aiming,
	Locked,
	NoAmmo
};



//Forward declaration
class UTankBarrel; //Holds Parameters for Barrels 
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYVECHILEGAME_API UAimComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	EAimingStates AimingState = EAimingStates::Reloading;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float projectilespeed);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void AimSetting(UTankBarrel* BarrelToSet, UTankTurret*TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	UPROPERTY(BlueprintReadWrite, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	EAimingStates GetAimingState() const;
	UFUNCTION(BlueprintCallable, Category = Setup)
	int GetAmmo() const;
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrel(FVector AimDirection);
	bool IsAiming();
	UAimComponent();
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	int32 AmmoLeft = 15;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimer = 3;

	float LastFireTime = 0;
	float ProjectileSpeed = 7500;
	FVector AimDirection;


};
