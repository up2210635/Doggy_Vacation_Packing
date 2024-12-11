// Fill out your copyright notice in the Description page of Project Settings.


#include "Choc_Item.h"
#include "Dog.h"
#include "Spawner.h"

AChoc_Item::AChoc_Item()
{
	IScore = -50;
	Attack = -75;
	Spawn_Index = BP_Choc_Item;
}

void AChoc_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn) 
	{
		Dog->Set_Score(IScore);
		Spawn->Repeat_Spawn(Spawn_Index);
		TakeDamage(Attack, Dog->Health);
		if (Dog->Health <= 0) 
		{
			Dog->ResetLevel();
		}
		Destroy();
	}
}

void AChoc_Item::TakeDamage(int Damage, int& HP)
{
	HP += Damage;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("HP: %i"), HP));
}