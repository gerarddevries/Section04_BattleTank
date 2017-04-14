// (c) 2016, United

#pragma once

#include "classTankPawn.h"
#include "GameFramework/PlayerController.h"
#include "classTankPlayerController.generated.h"   /// Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API AclassTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	AclassTankPawn* GetControlledTank() const;   /// get the controlled tank

	
	
};
