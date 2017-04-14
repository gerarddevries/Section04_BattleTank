// (c) 2016, United

#pragma once

#include "GameFramework/Pawn.h"
#include "classTankPawn.generated.h"

UCLASS()
class BATTLETANK_API AclassTankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AclassTankPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
