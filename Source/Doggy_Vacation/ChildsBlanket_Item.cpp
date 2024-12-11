// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildsBlanket_Item.h"
#include "Dog.h"
#include "Spawner.h"

AChildsBlanket_Item::AChildsBlanket_Item()
{
	IScore = 75;
	Time_Change = 10;
	Spawn_Index = BP_ChildsBlanket_Item;
}

void AChildsBlanket_Item::Pick_Up()
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
			Time_Changer(Time_Change, Dog->Time);
			Destroy();
		}
	}
}

void AChildsBlanket_Item::Time_Changer(float Change, int& Time)
{
	Time += Change;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Time: %i"), Time));
}
