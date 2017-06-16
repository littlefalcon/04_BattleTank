// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "BattleTank.h"
#include "Engine.h"



void UTankBarrel::Elevate(float RelativeSpeed) {
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees); // Limit Max/Min Value with Clamp
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
