// Fill out your copyright notice in the Description page of Project Settings.


#include "TeddyBear_Item.h"
#include "Dog.h"
#include "Spawner.h"
#include "Time_Singleton.h"

ATeddyBear_Item::ATeddyBear_Item()
{
	IScore = 100;
	Time_Change = 20.0f;
	Spawn_Index = BP_TeddyBear_Item;
}

void ATeddyBear_Item::Pick_Up()
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
			Time_Changer(Time_Change, Dog);
			Destroy();
		}
	}
}

void ATeddyBear_Item::Time_Changer(float Change, ADog* Dog)
{
	UTime_Singleton* STime = GetGameInstance()->GetSubsystem<UTime_Singleton>();
	STime->Add_Time(Change);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Time: %i"), STime->Get_Time()));;
}
