// (c) 2016, United

#include "BattleTank.h"
#include "classTankAIController.h"


/// ================================================================================
///  BeginPlay() overrides the original method from the ancestor: AActor
void AclassTankAIController::BeginPlay()
{
	Super::BeginPlay();   /// call the method from the ancestor

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	AclassTankPawn* L_pTankPawn = GetControlledTank();
	if (L_pTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s!"), *L_pTankPawn->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank!"));
	}

	AclassTankPawn* L_pPlayerControllerTankPawn = GetPlayerTank();
	if (L_pPlayerControllerTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("Found PlayerTank %s!"), *L_pPlayerControllerTankPawn->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No PlayerTank found!"));
	}

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
