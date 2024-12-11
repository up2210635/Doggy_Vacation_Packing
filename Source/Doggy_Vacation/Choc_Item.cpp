// Fill out your copyright notice in the Description page of Project Settings.


#include "Choc_Item.h"
#include "Dog.h"

AChoc_Item::AChoc_Item()
{
	IScore = -50;
	Attack = -75;
	Spawn_Index = BP_Choc_Item;
}

void AChoc_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog && Dog == Ptr) {
		Dog->Set_Score(IScore);
		TakeDamage(Attack, Dog->Health);
		if (Dog->Health <= 0) {
			Dog->ResetLevel();
		}
		Destroy();
	}
}

void AChoc_Item::TakeDamage(int Damage, int& HP)
{
	HP += Damage;
}