// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO Should this really tick?

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	if (!Barrel)
	{
		return;
	}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, WorldSpaceAim, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::TraceFullPath))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();

		MoveBarrel(AimDirection);

		auto WorldTime = GetWorld()->GetTimeSeconds();

		UE_LOG(LogTemp, Warning, TEXT("%f: Aim found!"), WorldTime);
	}
	else
	{
		auto WorldTime = GetWorld()->GetTimeSeconds();

		UE_LOG(LogTemp, Warning, TEXT("%f: No aim found!"), WorldTime);
	}

	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	// Work out diff between current rotation and direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;

	// Move barrel the right ammount this frame
	Barrel->Elevate(5); // TODO remove magic number
	// Given max elevation speed, at the frame time
}

