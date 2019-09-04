// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto WorldTime = GetWorld()->GetTimeSeconds();
	auto Name = GetName();

	UE_LOG(LogTemp, Warning, TEXT("%f: %s throttle is %f"), WorldTime, *Name, Throttle);

	// TODO Clamp throttle value so player can't over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}