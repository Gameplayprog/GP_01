// Fill out your copyright notice in the Description page of Project Settings.


#include "AimComponent.h"

// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAimComponent::barrelsetref(UStaticMeshComponent* ToBeSetBarrel)
{
	Barrel = ToBeSetBarrel;

}

// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimComponent::AimAt(FVector HitLocation)
{
	auto PlayerName = GetOwner()->GetName();
	auto GunLocation = Barrel->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming towards %s From %s"), *PlayerName, *HitLocation.ToString(), *GunLocation);
}



