// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Player = GetControlledTank();

	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s controlled"), *Player->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No tank controlled"), *Player->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}