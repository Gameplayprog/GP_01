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
	

public:
	ATank* GetControlledTank() const;

	//Getting begin play inherited from actor and overiding it 
	void BeginPlay() override;
};
