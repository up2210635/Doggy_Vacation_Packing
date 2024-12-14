// Fill out your copyright notice in the Description page of Project Settings.


#include "Steak_Item.h"
#include "Dog.h"
#include "Spawner.h"
#include "GameFramework/CharacterMovementComponent.h"

ASteak_Item::ASteak_Item()
{
	IScore = 75;
	Heal = 50;
	Time_Change = 10;
	Spawn_Index = BP_Steak_Item;
}

void ASteak_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn)
	{
		Dog->Set_Score(IScore);
		Spawn->Repeat_Spawn(Spawn_Index);
		TakeDamage(Heal, Dog);
		Time_Changer(Time_Change, Dog);
		Destroy();
	}
}

void ASteak_Item::TakeDamage(int Damage, ADog* Dog)
{
	Dog->Health += Damage;
	if (Dog->Health > 150)
		Dog->Health = 150;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("HP: %i"), Dog->Health));
}

void ASteak_Item::Time_Changer(float Change, ADog* Dog)
{
	Dog->Time += Change;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Time: %i"), Dog->Time));
}