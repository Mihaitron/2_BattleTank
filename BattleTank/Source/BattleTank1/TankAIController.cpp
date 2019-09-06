// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* Player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	if (Player)
	{
		// Move towards the player
		MoveToActor(Player, AcceptanceRadius); // TODO check radius in cm
		// Aim at the player
		ControlledTank->AimAt(Player->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire();
	}
}