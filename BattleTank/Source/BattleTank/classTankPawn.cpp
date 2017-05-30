// (c) 2016, United

#include "BattleTank.h"
#include "classTankPawn.h"


// Sets default values
AclassTankPawn::AclassTankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// manually create a component or subobject in code; this component will therefor be visible in blueprintTankPawn
	F_pTankAimingComponent = CreateDefaultSubobject<UclassTankAimingComponent>(FName("TankAimingComponent"));
}

// Called when the game starts or when spawned
void AclassTankPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AclassTankPawn::Tick( float P_floatDeltaTime)
{
	Super::Tick(P_floatDeltaTime);
}

// Called to bind functionality to input
void AclassTankPawn::SetupPlayerInputComponent(class UInputComponent* P_pInputComponent)
{
	Super::SetupPlayerInputComponent(P_pInputComponent);
}

//
void AclassTankPawn::AimAt(FVector P_vecHitLocation)
{
	F_pTankAimingComponent->AimAt(P_vecHitLocation);
}

void AclassTankPawn::SetBarrel(UStaticMeshComponent* P_pBarrel)
{
	F_pTankAimingComponent->SetBarrel(P_pBarrel);
}
