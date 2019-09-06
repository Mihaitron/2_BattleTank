// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	UE_LOG(LogTemp, Warning, TEXT("%s applies a force of %s to %s"), *GetOwner()->GetName(), *ForceApplied.ToString(), *GetName())

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}