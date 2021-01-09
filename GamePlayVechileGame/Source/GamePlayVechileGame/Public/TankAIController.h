// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


//Forward Declaration 
class ATank;
//class UAimComponent;

UCLASS()
class GAMEPLAYVECHILEGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

protected:

private:
	ATank* GetControlledTank() const;
	//how close the tank can get to the player 
	float AiRadius = 300;

	//Getting begin play inherited from actor and overiding it 
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

