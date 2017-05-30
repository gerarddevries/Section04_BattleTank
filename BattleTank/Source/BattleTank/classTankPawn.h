// (c) 2016, United

#pragma once

#include "classTankAimingComponent.h"   /// the aiming component will be used in classTankPawn 
#include "GameFramework/Pawn.h"
#include "classTankPawn.generated.h"    /// must be the last include

UCLASS()
class BATTLETANK_API AclassTankPawn : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector P_vecHitLocation);

	/// because of the UFUNCTION-macro SetBarrel is added as a function inside Unreal engine as well, in this case you can call it from Blueprint;
	/// the name of the parameter differs from the one used in the implementation (in the cpp-file); the name of the parameter below is used
	/// in Blueprint as name of the pin of the node, while the name of the parameter used in the implementation
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UStaticMeshComponent* Barrel);
	
protected:
	UclassTankAimingComponent* F_pTankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	AclassTankPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float P_floatDeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* P_pInputComponent) override;	
};
