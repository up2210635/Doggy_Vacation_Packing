// Fill out your copyright notice in the Description page of Project Settings.


#include "HotMug_Item.h"
#include "Dog.h"

AHotMug_Item::AHotMug_Item()
{
	IScore = -50;
	Attack = -50;
	Spawn_Index = BP_Mug_Item;
}

void AHotMug_Item::Pick_Up()
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

void AHotMug_Item::TakeDamage(int Damage, int& HP)
{
	HP += Damage;
}