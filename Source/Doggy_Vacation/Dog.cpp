// Fill out your copyright notice in the Description page of Project Settings.

#include "Dog.h"
#include "Components/StaticMeshComponent.h"
#include "Parent_Item.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ADog::ADog()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Jumping = false;
	Holding = false;
	Health = 100;
	Time = 120;
}

// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FRoundTime, this, &ADog::Counter, 1.0f, true, 0.0f);
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
	PlayerInputComponent->BindAction(TEXT("Interact"), IE_Pressed, this, &ADog::Kennel);
	PlayerInputComponent->BindAction(TEXT("Time"), IE_Pressed, this, &ADog::Print_Data);
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

void ADog::Kennel() {
	OnInteract.Broadcast();
}

void ADog::Print_Data()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("____________"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Time: %i"), Time));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Score: %i"), PScore));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("HP: %i"), Health));
	}
}

void ADog::Print()
{
	for (int i{}; i < Inventory.Num(); i++)
	{
		FString Name = UKismetSystemLibrary::GetDisplayName(Inventory[i]);
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Name);
	}
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

void ADog::Counter()
{
	if (Time != 0)
	{
		Time -= 1;
	}
	else
	{
		FName(FirstPersonMap) = *GetWorld()->GetName();
		UGameplayStatics::OpenLevel(GetWorld(), FirstPersonMap);
	}
}

void ADog::Add_Item(AParent_Item* Actor)
{
	Inventory.Add(Actor);
}

TSubclassOf<AParent_Item> ADog::Get_Items()
{
	if(Inventory.Top()->Actors)
		return Inventory.Top()->Actors;
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No item"));
		return nullptr;
	}
}

float ADog::Get_Time()
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(FRoundTime);
}

int ADog::Get_Spawn_index()
{
	return Inventory.Top()->Spawn_Index;
}

void ADog::Jump_Boost()
{
	GetCharacterMovement()->JumpZVelocity = 840.0f;
}