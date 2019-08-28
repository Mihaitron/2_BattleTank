// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Player = GetPlayerTank();

	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player %s found"), *Player->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player not found!"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Controller not found!"));

		return nullptr;
	}

	return Cast<ATank>(Player);
}