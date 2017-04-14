// (c) 2016, United

#include "BattleTank.h"
#include "classTankPawn.h"


// Sets default values
AclassTankPawn::AclassTankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AclassTankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AclassTankPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AclassTankPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

