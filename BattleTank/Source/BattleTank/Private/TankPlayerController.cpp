// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing : %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimtowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimtowardCrosshair()
{
	if (!GetControlledTank()) { return; }
	// Gew world location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}