// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ARogueCharacter::ARogueCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Rotates the character to face the direction it's moving in
	TObjectPtr<UCharacterMovementComponent> MovementComponent = this->GetCharacterMovement();
	MovementComponent->bOrientRotationToMovement = true;
	
	// Attach a USpringArmComponent to allow camera follow the Character
	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmComp"));
	CameraArmComp->SetupAttachment(RootComponent);
	// Rotate the arm with both controller's pitch(vertical) and yaw(horizontal) rotation inputs
	CameraArmComp->bUsePawnControlRotation = true;
	CameraArmComp->SetUsingAbsoluteRotation(true);
	
	// Attach a UCameraComponent
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraArmComp);
}

// Called when the game starts or when spawned
void ARogueCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

