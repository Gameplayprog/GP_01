// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "UObject/ConstructorHelpers.h"
void UTankBarrel::Elvate(float Relativespeed) 
{
	
	

}
UTankBarrel::UTankBarrel()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelAsset(TEXT("/Game/Tank/tank_fbx_Barrel"));
	this->SetStaticMesh(BarrelAsset.Object);
	this->SetRelativeLocation(FVector::ZeroVector);
}