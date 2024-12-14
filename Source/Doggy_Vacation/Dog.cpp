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

	//Configure character bools
	Jumping = false;
	Holding = false;

	// Configure character ints
	Health = 100;
	PScore = 0;
	Time = 120;
	Time_Remaining = 0;

	// Configure character movement
	Jump_Velocity = 420.0f; Set_Jump();
	Walk_Speed = 600.0f; Set_Walk();
	Step_Height = 45.0f; Set_Step();
	Gravity = 1.0f; Set_Gravity();
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

void ADog::Set_Jump()
{
	GetCharacterMovement()->JumpZVelocity = Jump_Velocity;
}

void ADog::Set_Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = Walk_Speed;
}

void ADog::Set_Step()
{
	GetCharacterMovement()->MaxStepHeight = Step_Height;
}

void ADog::Set_Gravity()
{
	GetCharacterMovement()->GravityScale = Gravity;
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

TSubclassOf<AParent_Item> ADog::Get_Items_Class()
{
	if(Inventory.Top()->Actors)
		return Inventory.Top()->Actors;
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Item_Class not found"));
		return nullptr;
	}
}

AParent_Item* ADog::Get_Item_ptr()
{
	if (Inventory.Top())
		return Inventory.Top();
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Item_ptr not found"));
		return nullptr;
	}
}

float ADog::Get_Time()
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(FRoundTime);
}