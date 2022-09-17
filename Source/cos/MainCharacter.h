// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"

#include "MainCharacter.generated.h"

UCLASS()
class COS_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* FirstPersonCamera;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void LookUpDown(float Val);
	void MoveForward(float Value);
	void MoveRight(float Value);
	void CrouchButtonPressed();
	void CrouchButtonReleased();
	void SetupMovementSettingsFromDataAsset();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	float CurrentVelocity;
	float DefaultVelocity;
	float CrouchVelocity;
	float JumpInitialVelocity;
	float MinPitchAngle;
	float MaxPitchAngle;
	float DefaultCameraPitchRotation;

	bool bIsCrouching = false;
};
