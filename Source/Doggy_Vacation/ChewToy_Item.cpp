// Fill out your copyright notice in the Description page of Project Settings.

#include "ChewToy_Item.h"
#include "Dog.h"
#include "Spawner.h"

AChewToy_Item::AChewToy_Item()
{
	IScore = 50;
	Spawn_Index = BP_ChewToy_Item;
	New_Jump = 840.0f;
	New_Step = 100.0f;
	New_Gravity = 2.0f;
}

void AChewToy_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn)
	{
		if(Dog->Get_Holding() == false)
		{
			Dog->Set_Holding(true);
			Dog->Set_Score(IScore);
			Dog->Add_Item(this);
			Spawn->Repeat_Spawn(Spawn_Index);
			Activate_Jump_Effects(New_Jump, New_Step, New_Gravity, Dog);
			Disable(this);
		}
	}
}

void AChewToy_Item::Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog)
{
	Dog->Set_Jump(Change_Jump);
	Dog->Set_Step(Change_Step);
	Dog->Set_Gravity(Change_Gravity);
	FJumpDelegate.BindUObject(this, &AChewToy_Item::Deactivate_Jump_Effects, Dog);
	GetWorld()->GetTimerManager().SetTimer(FJumpTimer, FJumpDelegate, 15.0f, false);
}

void AChewToy_Item::Deactivate_Jump_Effects(ADog* Dog)
{
	Dog->Set_Jump(420.0f);
	Dog->Set_Step(45.0f);
	Dog->Set_Gravity(1.0f);
}