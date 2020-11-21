// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"



UCLASS()
class GAMEPLAYVECHILEGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	



private:
	ATank* GetControlledTank() const;

	//Getting begin play inherited from actor and overiding it 
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATank* GetPlayerTank() const;
};

