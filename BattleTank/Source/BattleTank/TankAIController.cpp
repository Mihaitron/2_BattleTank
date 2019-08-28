// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AI = GetControlledTank();

	if (AI)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controls %s"), *AI->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI controls no tank"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}