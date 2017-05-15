// (c) 2016, United

#include "BattleTank.h"
#include "classTankAIController.h"


/// ================================================================================
///  BeginPlay() overrides the original method from the ancestor: AActor
void AclassTankAIController::BeginPlay()
{
	Super::BeginPlay();   /// call the method from the ancestor

	AclassTankPawn* L_pTankPawn = GetControlledTank();

	AclassTankPawn* L_pPlayerControllerTankPawn = GetPlayerTank();
}

/// ================================================================================
///  Tick() overrides the original method from the ancestor: AActor
void AclassTankAIController::Tick(float P_floatDeltaTime)
{
	Super::Tick(P_floatDeltaTime);   /// call the method from the ancestor

	if (!GetControlledTank()) { return; }

	// TODO move towards player

	// aim towards player
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	// TODO fire at player when ready
}

/// ================================================================================
//  Get the controlled tank
AclassTankPawn* AclassTankAIController::GetControlledTank() const
{
	/// get the pawn the AIController is currently possessing and cast it to an AclassTankPawn
	return Cast<AclassTankPawn>(GetPawn());
}

/// ================================================================================
//  Get the PlayerController tank
AclassTankPawn* AclassTankAIController::GetPlayerTank() const
{
	/// get the pawn the PlayerController is currently possessing and cast it to an AclassTankPawn
	return Cast<AclassTankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
