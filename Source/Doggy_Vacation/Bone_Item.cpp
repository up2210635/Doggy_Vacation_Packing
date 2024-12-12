// Fill out your copyright notice in the Description page of Project Settings.

#include "Bone_Item.h"
#include "Dog.h"
#include "Spawner.h"

ABone_Item::ABone_Item()
{
	IScore = 50;
	Spawn_Index = BP_Bone_Item;
}

void ABone_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn)
	{
		if (Dog->Holding == false)
		{
			Dog->Holding = true;
			Dog->Set_Score(IScore);
			Dog->Add_Item(this);
			Spawn->Repeat_Spawn(Spawn_Index);
			Change_Seed(1000.0f, Dog);
			Disable(this);
		}
	}
}

void ABone_Item::Change_Seed(float Change, ADog* Dog)
{
	Dog->Walk_Speed = Change;
	Dog->Set_Walk();
	FEffectsDelegate.BindUObject(this, &ABone_Item::Reset_speed, Dog);
	GetWorld()->GetTimerManager().SetTimer(FEffectsTimer, FEffectsDelegate, 15.0f, false);
}

void ABone_Item::Reset_speed(ADog* Dog)
{
	Dog->Walk_Speed = 600.0f;
	Dog->Set_Walk();
}