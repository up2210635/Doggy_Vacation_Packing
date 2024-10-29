// Fill out your copyright notice in the Description page of Project Settings.

#include "Dog.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADog::ADog()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Jumping = false;
}

// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Jumping) {
		Jump();
	}
}

// Called to bind functionality to input
void ADog::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ADog::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ADog::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ADog::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("Look"), this, &ADog::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ADog::CheckJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ADog::CheckJump);
}

void ADog::MoveForward(float AxisVal) {
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void ADog::MoveRight(float AxisVal) {
	AddMovementInput(GetActorRightVector() * AxisVal);
}

void ADog::CheckJump() {
	if (Jumping)
		Jumping = false;
	else
		Jumping = true;
}