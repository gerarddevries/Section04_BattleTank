// (c) 2016, United

#pragma once

#include "GameFramework/Pawn.h"
#include "classTankPawn.generated.h"

UCLASS()
class BATTLETANK_API AclassTankPawn : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector P_vecHitLocation);

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
