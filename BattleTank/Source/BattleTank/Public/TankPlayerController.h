// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
		float LintTraceRange = 1000000.f;

	//Return an Out parameter, true if hit landscape

	ATank* GetControlledTank() const;

	//Start the tank moving the barrel so that a shot whold hit where
	//the crosshair intersects the world
	void AimtowardCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
