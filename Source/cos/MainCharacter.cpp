// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"

#include "MovementData.h"
#include "GameFramework/CharacterMovementComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCamera->SetupAttachment(RootComponent);
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	SetupMovementSettingsFromDataAsset();

	const auto MovementComponent = GetCharacterMovement();
	if (IsValid(MovementComponent))
	{
		MovementComponent->JumpZVelocity = JumpInitialVelocity;
	}
	
	CurrentVelocity = DefaultVelocity;
}

void AMainCharacter::SetupMovementSettingsFromDataAsset()
{
	const auto MainCharacterMovementSettings = GetMutableDefault<UMainCharacterMovementSettings>();

	if (!IsValid(MainCharacterMovementSettings))
	{
		return;
	}

	const auto MovementSettings = MainCharacterMovementSettings->GetMovementSettings();
	DefaultVelocity = MovementSettings->DefaultVelocityFactor;
	CrouchVelocity = MovementSettings->CrouchVelocityFactor;
	JumpInitialVelocity = MovementSettings->JumpInitialVelocity;
	MinPitchAngle = MovementSettings->MinPitchAngle;
	MaxPitchAngle = MovementSettings->MaxPitchAngle;
	DefaultCameraPitchRotation = FirstPersonCamera->GetRelativeRotation().Pitch;
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO: Add crouch camera swift
}

void AMainCharacter::LookUpDown(float Value)
{
	auto Rotation = FirstPersonCamera->GetRelativeRotation();
	Rotation.Pitch = FMath::ClampAngle(Rotation.Pitch - Value, MinPitchAngle, MaxPitchAngle);
	FirstPersonCamera->SetRelativeRotation(Rotation);
}

void AMainCharacter::MoveForward(float Value)
{
	if (!FMath::IsNearlyEqual(Value, 0.0))
	{
		const auto MoveValue = Value * CurrentVelocity;
		AddMovementInput(GetActorForwardVector(), MoveValue);
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if (!FMath::IsNearlyEqual(Value, 0.0))
	{
		const auto MoveValue = Value * CurrentVelocity;
		AddMovementInput(GetActorRightVector(), MoveValue);
	}
}

void AMainCharacter::CrouchButtonPressed()
{
	bIsCrouching = true;
	CurrentVelocity = CrouchVelocity;
}

void AMainCharacter::CrouchButtonReleased()
{
	bIsCrouching = false;
	CurrentVelocity = DefaultVelocity;
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AMainCharacter::MoveRight);

	PlayerInputComponent->BindAction("CrouchModifier", IE_Pressed, this, &AMainCharacter::CrouchButtonPressed);
	PlayerInputComponent->BindAction("CrouchModifier", IE_Released, this, &AMainCharacter::CrouchButtonReleased);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &AMainCharacter::LookUpDown);
}

