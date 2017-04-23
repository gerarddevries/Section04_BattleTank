// (c) 2016, United

#include "BattleTank.h"
#include "classTankPlayerController.h"


/// ================================================================================
///  BeginPlay() overrides the original method from the ancestor: AActor
void AclassTankPlayerController::BeginPlay()
{
	Super::BeginPlay();   /// call the method from the ancestor

	AclassTankPawn* L_pTankPawn = GetControlledTank();
	if (L_pTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s!"), *L_pTankPawn->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank!"));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

/// ================================================================================
///  Tick() overrides the original method from the ancestor: AActor
void AclassTankPlayerController::Tick(float P_floatDeltaTime)
{
	Super::Tick(P_floatDeltaTime);   /// call the method from the ancestor

	AimTowardsCrosshair();
}

/// ================================================================================
//  get the controlled tank
AclassTankPawn* AclassTankPlayerController::GetControlledTank() const
{
	return Cast<AclassTankPawn>(GetPawn());   /// get the pawn the PlayerController is currently possessing and cast it to a ATank
}

/// ================================================================================
//  start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
void AclassTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector L_vecHitLocation;   // Out parameter, so initialising it is not necessary
	if (GetSightRayHitLocation(L_vecHitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *L_vecHitLocation.ToString());

		// TODO tell controlled tank to aim at this point
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: no target"));
	}
}

/// ================================================================================
//  get world location of linetrace through crosshair, return true if landscape hit
bool AclassTankPlayerController::GetSightRayHitLocation(FVector& P_vecOutHitLocation) const
{
	P_vecOutHitLocation = FVector(1.0);
	return true;
}
