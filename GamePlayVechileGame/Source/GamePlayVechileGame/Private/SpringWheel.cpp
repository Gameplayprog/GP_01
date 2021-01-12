// For Educational use only


#include "SpringWheel.h"

// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spring = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Spring"));
	SetRootComponent(spring);

	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(spring);
	wheel = CreateDefaultSubobject<USphereComponent>(FName("wheel"));
	wheel->SetupAttachment(Axle);
	Axlespring = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Axle spring"));
	Axlespring->SetupAttachment(Axle);
}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	SetupConstaints();
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASpringWheel::SetupConstaints()
{

	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* RootBody = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!RootBody) { return; }
	spring->SetConstrainedComponents(RootBody, NAME_None, Axle, NAME_None);
	Axlespring->SetConstrainedComponents(Axle, NAME_None, wheel, NAME_None);

}
