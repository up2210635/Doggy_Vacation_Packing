// Fill out your copyright notice in the Description page of Project Settings.


#include "Steak_Item.h"
#include "Dog.h"
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
	if (Dog && Dog == Ptr)
	{
		Dog->Set_Score(IScore);
		TakeDamage(Heal, Dog->Health);
		Time_Changer(Time_Change, Dog->Time);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("____________"));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Time: %i"), Dog->Time));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("HP: %i"), Dog->Health));
		}
		Destroy();
	}
}

void ASteak_Item::TakeDamage(int Damage, int& HP)
{
	HP += Damage;
}

void ASteak_Item::Time_Changer(float Change, int& Time)
{
	Time += Change;
}