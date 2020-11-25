// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "AimComponent.generated.h"

//Forward declaration
class UTankBarrel; //Holds Parameters for Barrels 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYVECHILEGAME_API UAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimComponent();

	void barrelsetref(UTankBarrel* ToBeSetBarrel);



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float projectilespeed);
private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);

		
};
