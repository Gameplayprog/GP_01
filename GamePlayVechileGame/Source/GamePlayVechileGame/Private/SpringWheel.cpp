// For Educational use only


#include "SpringWheel.h"

// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spring = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Spring"));
	SetRootComponent(spring);
	mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("mass"));
	mass->SetupAttachment(spring);
	wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("wheel"));
	wheel->SetupAttachment(spring);
}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	if (GetAttachParentActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not null"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" null"));
	}
	
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

