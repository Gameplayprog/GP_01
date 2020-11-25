// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

///Forward declaration 
class UTankBarrel; 
class UAimComponent;

UCLASS()
class GAMEPLAYVECHILEGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation, float ProjectileSpeed);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void ToBeSetBarrelRef(UTankBarrel* ToSetBarrel);

	UPROPERTY(EditAnywhere, Category = Firing)
	float ProjectileSpeed = 100000;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UAimComponent* Tankaimingcomponent = nullptr;


private:	
	// Sets default values for this pawn's properties
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;





};
