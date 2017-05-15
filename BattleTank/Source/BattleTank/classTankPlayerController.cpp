// (c) 2016, United

#include "BattleTank.h"
#include "classTankPlayerController.h"


/// ================================================================================
///  BeginPlay() overrides the original method from the ancestor: AActor
void AclassTankPlayerController::BeginPlay()
{
	Super::BeginPlay();   /// call the method from the ancestor

	AclassTankPawn* L_pTankPawn = GetControlledTank();
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
		// tell controlled tank to aim at this point
		GetControlledTank()->AimAt(L_vecHitLocation);
	}
}

/// ================================================================================
//  get world location of linetrace through crosshair, return true if landscape hit
bool AclassTankPlayerController::GetSightRayHitLocation(FVector& P_vecOutHitLocation) const
{
	/// find the crosshair position (on screen)
	int32 L_intViewportWidth;
	int32 L_intViewportHeight;
	GetViewportSize(L_intViewportWidth, L_intViewportHeight);
	FVector2D L_vec2dScreenLocation = FVector2D(L_intViewportWidth * CrossHairLocationX, L_intViewportHeight * CrossHairLocationY);
	
	/// "de-project" the screen position of the crosshair to a world direction (i.e. look direction)
	FVector L_vecLookDirection;
	if (GetLookDirection(L_vec2dScreenLocation, L_vecLookDirection)) {
		/// line-trace along that look direction and see what we hit (up to max range)
		if (GetLookVectorHitLocation(L_vecLookDirection, P_vecOutHitLocation)) { return true; }
	}

	return false;
}

/// ================================================================================
//  "de-project" the screen position of the crosshair to a world direction (i.e. look direction)
bool AclassTankPlayerController::GetLookDirection(FVector2D P_vec2dScreenLocation, FVector& P_vecLookDirection) const
{
	FVector L_vecWorldLocation;   /// dummy variable; we don't need the value it gets back from DeprojectScreenPositionToWorld
	return DeprojectScreenPositionToWorld(P_vec2dScreenLocation.X, P_vec2dScreenLocation.Y, L_vecWorldLocation, P_vecLookDirection);
}

/// ================================================================================
//  get the position, i.e. vector, of the location where there is a hit (if any)
bool AclassTankPlayerController::GetLookVectorHitLocation(FVector P_vecLookDirection, FVector& P_vecHitLocation) const
{
	/// setup collision query parameters
	FCollisionQueryParams L_pTraceParameters(
		FName(TEXT("")),
		false,       /// bInTraceComplex; = false: use simple structures of objects for collision; = true: use complex structures of objects for collision
		GetOwner()   /// ignore ourselves
	);

	FHitResult L_pHitResult;
	// get th vector of the position of camera (not the position of the player!), i.e. the start of the line trace
	FVector L_vecLineTraceStart = PlayerCameraManager->GetCameraLocation();
	//  get the vector for the end of the line trace
	FVector L_vecLineTraceEnd = L_vecLineTraceStart + P_vecLookDirection * F_floatLineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(
			L_pHitResult,
			L_vecLineTraceStart,
			L_vecLineTraceEnd,
			ECollisionChannel::ECC_Visibility   /// if you can see it, you can hit it
			)) {
		P_vecHitLocation = L_pHitResult.ImpactPoint;
		return true;
	}
	
	return false;   // line trace didn't succeed
}
