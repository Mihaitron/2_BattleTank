// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto WorldTime = GetWorld()->GetTimeSeconds();

	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed %f"), WorldTime, RelativeSpeed);
}