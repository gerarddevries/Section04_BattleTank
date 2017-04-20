// (c) 2016, United

#pragma once

#include "classTankPawn.h"
#include "AIController.h"
#include "classTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AclassTankAIController : public AAIController
{
	GENERATED_BODY()

public:
	/// - override the BeginPlay() from the last ancestor that has the method: AActor, and add functionality to it
	/// - prefix "virtual" to make sure possible children can override this method (doesn't do anything in this case since the original method was 
	///   already virtual
	virtual void BeginPlay() override;

	AclassTankPawn* GetControlledTank() const;   /// get the controlled tank
};