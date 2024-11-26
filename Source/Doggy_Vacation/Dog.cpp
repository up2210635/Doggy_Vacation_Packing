// Fill out your copyright notice in the Description page of Project Settings.

#include "Dog.h"
#include "Components/StaticMeshComponent.h"
#include "Parent_Item.h"

// Sets default values
ADog::ADog()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Jumping = false;
	Health = 100;
	Time = 120;
}

// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FRoundTime, this, &ADog::ResetLevel, Time, false);
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
void ADog::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ADog::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ADog::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ADog::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("Look"), this, &ADog::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ADog::CheckJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ADog::CheckJump);
	PlayerInputComponent->BindAction(TEXT("Spawn"), IE_Pressed, this, &ADog::Spawn);
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

void ADog::Spawn() {
	OnSpawn.Broadcast();
}

void ADog::Print_Time()
{
	float Test = GetWorld()->GetTimerManager().GetTimerRemaining(FRoundTime);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Time left: ");
}

void ADog::Set_Score(int Change)
{
	PScore += Change;
}

void ADog::ResetLevel()
{
	FName(FirstPersonMap) = *GetWorld()->GetName();
	UGameplayStatics::OpenLevel(GetWorld(), FirstPersonMap);
}

void ADog::Add_Item(AParent_Item* Actor)
{
	Items.Add(Actor);
}