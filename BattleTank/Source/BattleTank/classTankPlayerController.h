// (c) 2016, United

#pragma once

#include "classTankPawn.h"
#include "GameFramework/PlayerController.h"
#include "classTankPlayerController.generated.h"   /// must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API AclassTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	/// - override the BeginPlay() from the last ancestor that has the method: AActor, and add functionality to it
	/// - prefix "virtual" to make sure possible children can override this method (doesn't do anything in this case since the original method was 
	///   already virtual
	virtual void BeginPlay() override;
	/// - override the Tick() from the last ancestor that has the method: AActor, and add functionality to it
	/// - prefix "virtual" to make sure possible children can override this method (doesn't do anything in this case since the original method was 
	///   already virtual
	virtual void Tick(float P_floatDeltaTime) override;

private:
	/// because of the UPROPERTY-macro CrossHairLocationX is added as a property inside Unreal engine as well
	/// define F_floatCrossHairLocationX as alias for CrossHairLocationX to conform Gerard's naming conventions
	/// The value is semi-hardcoded to save the time to read the position from the UI-widget. The downside is that, if the position of the
	/// crosshair is changed in the widget, this value has to be manually changed as well; either in code or in Blueprint
	UPROPERTY(EditAnywhere)
	float CrossHairLocationX = 0.5;
	float& F_floatCrossHairLocationX = CrossHairLocationX;
	/// because of the UPROPERTY-macro CrossHairLocationY is added as a property inside Unreal engine as well
	/// define F_floatCrossHairLocationY as alias for CrossHairLocationY to conform Gerard's naming conventions
	/// the value is semi-hardcoded to save the time to read the position from the UI-widget
	/// crosshair is changed in the widget, this value has to be manually changed as well; either in code or in Blueprint
	UPROPERTY(EditAnywhere)
	float CrossHairLocationY = 0.33333;
	float& F_floatCrossHairLocationY = CrossHairLocationY;

	/// get the controlled tank
	AclassTankPawn* GetControlledTank() const;
	/// start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	/// get world location of linetrace through crosshair, return true if landscape hit
	bool GetSightRayHitLocation(FVector& P_vecOutHitLocation) const;
	/// "de-project" the screen position of the crosshair to a world direction (i.e. look direction)
	bool GetLookDirection(FVector2D P_vec2dScreenLocation, FVector& LookDirection) const;
};
