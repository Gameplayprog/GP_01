// For Educational use only

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "SpringWheel.generated.h"

UCLASS()
class GAMEPLAYVECHILEGAME_API ASpringWheel : public AActor
{
	GENERATED_BODY()
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ASpringWheel();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddForce(float Throw);
private:
	void SetupConstaints();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* wheel = nullptr;

	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* spring = nullptr;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Axle = nullptr;

	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* Axlespring = nullptr;

};
