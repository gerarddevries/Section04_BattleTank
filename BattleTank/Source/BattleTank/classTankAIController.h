// (c) 2016, United

#pragma once

#include "classTankPawn.h"
#include "AIController.h"
#include "classTankAIController.generated.h"   /// must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API AclassTankAIController : public AAIController
{
	GENERATED_BODY()

private:
	/// - override the BeginPlay() from the last ancestor that has the method: AActor, and add functionality to it
	/// - prefix "virtual" to make sure possible children can override this method (doesn't do anything in this case since the original method was 
	///   already virtual
	virtual void BeginPlay() override;
	/// - override the Tick() from the last ancestor that has the method: AActor, and add functionality to it
	/// - prefix "virtual" to make sure possible children can override this method (doesn't do anything in this case since the original method was 
	///   already virtual
	virtual void Tick(float P_floatDeltaTime) override;
	// get the controlled tank
	AclassTankPawn* GetControlledTank() const;         
	// get the tank from the player, i.e. the PlayerController
	AclassTankPawn* GetPlayerTank() const;             
};
