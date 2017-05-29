// (c) 2016, United

#include "BattleTank.h"
#include "classTankAimingComponent.h"


// Sets default values for this component's properties
UclassTankAimingComponent::UclassTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UclassTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UclassTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

//
void UclassTankAimingComponent::AimAt(FVector P_vecHitLocation)
{
	FString L_strCurrentTankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s!"), *L_strCurrentTankName, *P_vecHitLocation.ToString());
}

