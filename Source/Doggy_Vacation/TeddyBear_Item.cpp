// Fill out your copyright notice in the Description page of Project Settings.


#include "TeddyBear_Item.h"
#include "Dog.h"

ATeddyBear_Item::ATeddyBear_Item()
{
	IScore = 100;
	Time_Change = 20;
	Spawn_Index = BP_TeddyBear_Item;
}

void ATeddyBear_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog && Dog == Ptr)
	{
		if (Dog->Holding == false)
		{
			Dog->Holding = true;
			Dog->Set_Score(IScore);
			Dog->Add_Item(this);
			Time_Changer(Time_Change, Dog->Time);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("____________"));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Time: %i"), Dog->Time));
			}
			Destroy();
		}
	}
}

void ATeddyBear_Item::Time_Changer(float Change, int& Time)
{
	Time += Change;
}
