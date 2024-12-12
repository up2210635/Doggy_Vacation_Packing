// Fill out your copyright notice in the Description page of Project Settings.

#include "ChewToy_Item.h"
#include "Dog.h"
#include "Spawner.h"

AChewToy_Item::AChewToy_Item()
{
	IScore = 50;
	Spawn_Index = BP_ChewToy_Item;
}

void AChewToy_Item::Pick_Up()
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
			Activate_Jump_Boost(840.0f, 100.0f, Dog);
			Disable(this);
		}
	}
}

void AChewToy_Item::Activate_Jump_Boost(float Change_Jump, float Change_Step, ADog* Dog)
{
	Dog->Jump_Velocity = Change_Jump;
	Dog->Step_Height = Change_Step;
	Dog->Set_Jump();
	Dog->Set_Step();
	FEffectsDelegate.BindUObject(this, &AChewToy_Item::Deactivate_Jump_boost, Dog);
	GetWorld()->GetTimerManager().SetTimer(FEffectsTimer, FEffectsDelegate, 15.0f, false);
}

void AChewToy_Item::Deactivate_Jump_boost(ADog* Dog)
{
	Dog->Jump_Velocity = 420.0f;
	Dog->Step_Height = 45.0f;
	Dog->Set_Jump();
	Dog->Set_Step();
}