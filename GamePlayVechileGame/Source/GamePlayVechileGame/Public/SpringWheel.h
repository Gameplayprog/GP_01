// For Educational use only

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "SpringWheel.generated.h"

UCLASS()
class GAMEPLAYVECHILEGAME_API ASpringWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ASpringWheel();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetupConstaints();
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* wheel = nullptr;
	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* spring = nullptr;

};
