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
//  Get the controlled tank
AclassTankPawn* AclassTankPlayerController::GetControlledTank() const
{
	return Cast<AclassTankPawn>(GetPawn());   /// get the pawn the PlayerController is currently possessing and cast it to a ATank
}


