// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"
#include "BattleTank.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	FRotator NewRotation = FRotator(0, Rotation, 0);
	SetRelativeRotation(NewRotation);
	UE_LOG(LogTemp, Warning, TEXT("%s Rotate pos"), *NewRotation.ToString());
}

