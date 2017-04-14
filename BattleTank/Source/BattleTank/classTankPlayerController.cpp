// (c) 2016, United

#include "BattleTank.h"
#include "classTankPlayerController.h"


/// ================================================================================
//  Get the controlled tank
AclassTankPawn* AclassTankPlayerController::GetControlledTank() const
{
	return Cast<AclassTankPawn>(GetPawn());   // get the pawn the PlayerController is currently possessing and cast it to a ATank
}


