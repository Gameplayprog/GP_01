// For Educational use only

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnWheel.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYVECHILEGAME_API USpawnWheel : public USceneComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AActor> Spawn;

	// Sets default values for this component's properties
	USpawnWheel();

	AActor* SpawnedActorGetter()const { return SpawnedActor; };
private:
	UPROPERTY()
	AActor* SpawnedActor;
};
