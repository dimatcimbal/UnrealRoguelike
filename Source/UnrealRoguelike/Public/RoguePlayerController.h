// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RoguePlayerController.generated.h"

class ARogueCharacter;
struct FInputActionValue;

class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class UNREALROGUELIKE_API ARoguePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> CurrentInputMappingContext{nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction{nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
        TObjectPtr<UInputAction> LookAction{nullptr};
	
	TObjectPtr<ARogueCharacter> CurrentCharacter;
	
        virtual void SetupInputComponent() override;

protected:
        virtual void OnPossess(APawn *InPawn) override;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
};
