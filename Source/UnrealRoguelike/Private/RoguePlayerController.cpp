// Fill out your copyright notice in the Description page of Project Settings.

#include "RoguePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystemInterface.h"
#include "EnhancedInputSubsystems.h"
#include "RogueCharacter.h"

// Called to bind functionality to input
void ARoguePlayerController::SetupInputComponent() {
  Super::SetupInputComponent();

  if (UEnhancedInputComponent *EnhancedInputComponent =
          CastChecked<UEnhancedInputComponent>(this->InputComponent)) {
    
    // Bind Move
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered,
                                       this, &ARoguePlayerController::Move);

    // Bind Look
    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered,
                                       this, &ARoguePlayerController::Look);
  }
}

void ARoguePlayerController::OnPossess(APawn *InPawn) {
  Super::OnPossess(InPawn);

  this->CurrentCharacter = Cast<ARogueCharacter>(InPawn);

  if (const TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputLocalPlayerSubsystem =
    ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
  {
    InputLocalPlayerSubsystem->AddMappingContext(this->CurrentInputMappingContext, 0);
  }
}

void ARoguePlayerController::Move(const FInputActionValue& Value) {
  const FVector2D InputValue =  Value.Get<FVector2D>();
  UE_LOG(LogTemp, Log, TEXT("Move Input: X=%f, Y=%f"), InputValue.X, InputValue.Y);
  
  const FRotator Rotation = this->GetControlRotation();
  const FRotator YawRotation{0, Rotation.Yaw, 0};

  const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
  const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
  
  this->CurrentCharacter->AddMovementInput(ForwardDirection, InputValue.X);
  this->CurrentCharacter->AddMovementInput(RightDirection, InputValue.Y);
}

void ARoguePlayerController::Look(const FInputActionValue &Value) {
  const FVector2D InputValue =  Value.Get<FVector2D>();
  UE_LOG(LogTemp, Log, TEXT("Look Input: X=%f, Y=%f"), InputValue.X, InputValue.Y);
  
  this->CurrentCharacter->AddControllerYawInput(InputValue.X);
  this->CurrentCharacter->AddControllerPitchInput(InputValue.Y);
}

