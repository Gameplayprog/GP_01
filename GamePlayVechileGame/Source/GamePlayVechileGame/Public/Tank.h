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

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTDelegate);
UCLASS()
class GAMEPLAYVECHILEGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation, float ProjectileSpeed);
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ProjectileSpeed = 7500;
	//returns between 0-1 for %
	UFUNCTION(BlueprintPure, Category = HP)
	float HealthGetter() const;

	FTDelegate Death;
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
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)override;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 Health = 80;
	UPROPERTY(VisibleAnywhere, Category = HP)
	int32 Chealth;
};
