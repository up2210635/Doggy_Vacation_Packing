// Fill out your copyright notice in the Description page of Project Settings.

#include "Bone_Item.h"
#include "Dog.h"
#include "Spawner.h"

ABone_Item::ABone_Item()
{
	IScore = 50;
	Spawn_Index = BP_Bone_Item;
	New_Walk = 400.0f;
}

void ABone_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn)
	{
		if(Dog->Get_Holding() == false)
		{
			Dog->Set_Holding(true);
			Dog->Add_Score(IScore);
			Dog->Add_Item(this);
			Spawn->Repeat_Spawn(Spawn_Index);
			Change_Seed(New_Walk, Dog);
			Disable(this);
		}
	}
}

void ABone_Item::Change_Seed(float Change, ADog* Dog)
{
	Dog->Add_Walk(Change);
	FSpeedDelegate.BindUObject(this, &ABone_Item::Undo_Seed_Effects, New_Walk, Dog);
	GetWorld()->GetTimerManager().SetTimer(FSpeedTimer, FSpeedDelegate, 15.0f, false);
}

void ABone_Item::Undo_Seed_Effects(float Walk, ADog* Dog)
{
	Dog->Subtract_Walk(Walk);
}