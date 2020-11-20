// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "VechilePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYVECHILEGAME_API AVechilePlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:
	ATank* GetControlledTank() const;
	//Getting begin play inherited from actor and overiding it 
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//start the Vechile mocing gun so that the show would hit where crosshair itersects world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation ) const;
	
	UPROPERTY(EditAnywhere)
	float crosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float crosshairYLocation = 0.3333;
};
