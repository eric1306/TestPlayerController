// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/TPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/TCharacterBase.h"
#include "Components/InputComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ATPlayerController::ATPlayerController()
{
	UE_LOG(LogTemp, Log, TEXT("ATPlayerController Called"));
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextRef(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/ThirdPerson/Input/IMC_Default.IMC_Default'"));
	if (nullptr != InputMappingContextRef.Object)
	{
		InputMappingContext = InputMappingContextRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ThirdPerson/Input/Actions/IA_Move.IA_Move'"));
	if (nullptr != MoveActionRef.Object)
	{
		MoveAction = MoveActionRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> LookActionRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ThirdPerson/Input/Actions/IA_Look.IA_Look'"));
	if (nullptr != LookActionRef.Object)
	{
		LookAction = LookActionRef.Object;
	}
	/*static ConstructorHelpers::FObjectFinder<UInputAction> JumpActionRef(TEXT(""));
	if (nullptr != JumpActionRef.Object)
	{
		JumpAction = JumpActionRef.Object;
	}*/
}

void ATPlayerController::BeginPlay()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
		//Subsystem->RemoveMappingContext(DefaultMappingContext);
	}
}

void ATPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent)
	{
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, );
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATPlayerController::LookAct);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATPlayerController::MoveAct);
	}
}

void ATPlayerController::LookAct(const FInputActionValue& Value)
{
	//Get Pawn Class
	ATCharacterBase* ControlledCharacter = Cast<ATCharacterBase>(GetPawn());
	//if Pawn Exist
	if (ControlledCharacter) 
	{
		//Execute Mapping Function
		ControlledCharacter->Look(Value);
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("Pawn Not Exist"));
	}
}

void ATPlayerController::MoveAct(const FInputActionValue& Value)
{
	ATCharacterBase* ControlledCharacter = Cast<ATCharacterBase>(GetPawn());
	if (ControlledCharacter)
	{
		ControlledCharacter->Move(Value);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Pawn Not Exist"));
	}
}


