// Ryan Becks Work

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
	
	

	

	//TODO REMOVE
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ProjectileSpeed = 7500;

protected:
	UPROPERTY(BlueprintReadOnly)
	UAimComponent* Tankaimingcomponent = nullptr;
private:	
	// Sets default values for this pawn's properties
	ATank();


	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimer = 3; 
	float LastFireTime = 0;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

};
