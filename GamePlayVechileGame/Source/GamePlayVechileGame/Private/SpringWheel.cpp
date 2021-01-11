// For Educational use only


#include "SpringWheel.h"

// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("mass"));
	SetRootComponent(mass);
	wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("wheel"));
	wheel->SetupAttachment(mass);
	spring = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Spring"));
	spring->SetupAttachment(mass);
}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

