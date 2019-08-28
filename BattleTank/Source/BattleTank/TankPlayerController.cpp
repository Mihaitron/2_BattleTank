// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Player = GetControlledTank();

	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controls %s"), *Player->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player controls no tank!"), *Player->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation; // OUT parameter

	if (GetSightRayHitLocation(&HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

		// tell conterolled tank to aim at  this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector* OutHitLocation) const
{
	*OutHitLocation = FVector(1.0);
	return true;
}