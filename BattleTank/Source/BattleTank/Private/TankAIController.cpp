// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing : %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found : %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		//TODO Move towards the player

		// Aim towards the player
		//FVector PlayerLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("AI %s found : %s"), *(GetControlledTank()->GetName()), *(PlayerLocation.ToString()));
		// Fire if ready
	}
	
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //Get each of ai in level เก็ทพาว ของรถถังคันที่มี TankAIController.cpp แป๊ะสคริปไว้อยู่
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
 


