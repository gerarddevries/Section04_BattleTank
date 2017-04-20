// (c) 2016, United

#include "BattleTank.h"
#include "classTankAIController.h"


/// ================================================================================
///  BeginPlay() overrides the original method from the ancestor: AActor
void AclassTankAIController::BeginPlay()
{
	Super::BeginPlay();   /// call the method from the ancestor

	AclassTankPawn* L_pTankPawn = GetControlledTank();
	if (L_pTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s!"), *L_pTankPawn->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank!"));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

/// ================================================================================
//  Get the controlled tank
AclassTankPawn* AclassTankAIController::GetControlledTank() const
{
	return Cast<AclassTankPawn>(GetPawn());   /// get the pawn the PlayerController is currently possessing and cast it to a ATank
}
