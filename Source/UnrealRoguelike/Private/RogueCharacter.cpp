// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ARogueCharacter::ARogueCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Attach a USpringArmComponent to allow camera follow the Character
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	// Attach a UCameraComponent
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
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

