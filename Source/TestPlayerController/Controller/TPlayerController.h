// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "TPlayerController.generated.h"
/**
 * 
 */
UCLASS()
class TESTPLAYERCONTROLLER_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATPlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	UPROPERTY()
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY()
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY()
	TObjectPtr<class UInputAction> LookAction;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	//TObjectPtr<class UInputAction> JumpAction;

	void LookAct(const FInputActionValue& Value);
	void MoveAct(const FInputActionValue& Value);

};
