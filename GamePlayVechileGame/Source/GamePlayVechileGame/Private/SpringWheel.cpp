// For Educational use only


#include "SpringWheel.h"

// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;
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
	wheel->SetNotifyRigidBodyCollision(true);
	wheel->OnComponentHit.AddDynamic(this, &ASpringWheel::OnHit);
	SetupConstaints();
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetWorld()->TickGroup == TG_PostPhysics)
	{
		ThrowThisFrame = 0;
	}

}
void ASpringWheel::AddForce(float Throw)
{
	ThrowThisFrame += Throw;
}
void ASpringWheel::GiveForce()
{
	wheel->AddForce(Axle->GetForwardVector() * ThrowThisFrame);
}
void ASpringWheel::SetupConstaints()
{

	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* RootBody = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!RootBody) { return; }
	spring->SetConstrainedComponents(RootBody, NAME_None, Axle, NAME_None);
	Axlespring->SetConstrainedComponents(Axle, NAME_None, wheel, NAME_None);

}

void ASpringWheel::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	GiveForce();
}
