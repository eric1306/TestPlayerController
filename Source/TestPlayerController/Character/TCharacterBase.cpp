// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TCharacterBase.h"

// Sets default values
ATCharacterBase::ATCharacterBase()
{

}

// Called when the game starts or when spawned
void ATCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATCharacterBase::Move(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Move Active"));
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);
}

void ATCharacterBase::Look(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Look Active"));
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

