// Ryan Beck

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VechilePlayerController.generated.h"

/**
 * Player controller
 */
 //Forward Declaration
class AimComponent;
UCLASS()
class GAMEPLAYVECHILEGAME_API AVechilePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = setup)
		void AimCompFound(UAimComponent* AimCompRef);


private:
	//Getting begin play inherited from actor and overiding it 
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//start the Vechile mocing gun so that the show would hit where crosshair itersects world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float crosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float crosshairYLocation = 0.3333;

	bool GetDirectionOFlook(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetVectorHitLocation(FVector LookDirection, FVector TraceEndLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float TraceRange = 1000000.;
};