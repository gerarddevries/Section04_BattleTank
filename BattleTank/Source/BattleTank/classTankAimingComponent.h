// (c) 2016, United

#pragma once

#include "Components/ActorComponent.h"
#include "classTankAimingComponent.generated.h"   /// must be the last include


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UclassTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UclassTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//
	void AimAt(FVector P_vecHitLocation);
	
};
