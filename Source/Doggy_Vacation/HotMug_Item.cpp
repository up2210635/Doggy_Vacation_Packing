// Fill out your copyright notice in the Description page of Project Settings.


#include "HotMug_Item.h"
#include "Dog.h"
#include "Spawner.h"

AHotMug_Item::AHotMug_Item()
{
	IScore = -50;
	Attack = -50;
	Spawn_Index = BP_Mug_Item;
	New_Jump    = 210.0f;
	New_Step    = 20.0f;
	New_Gravity = 0.25f;
	New_Walk    = 150.0f;
}

void AHotMug_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn) 
	{
		Dog->Set_Score(IScore);
		Spawn->Repeat_Spawn(Spawn_Index);
		TakeDamage(Attack, Dog);
		Activate_Jump_Effects(New_Jump, New_Step, New_Gravity, Dog);
		Change_Seed(New_Walk, Dog);
		Disable(this);
	}
}

void AHotMug_Item::TakeDamage(int Damage, ADog* Dog)
{
	Dog->Add_Health(Damage);
	if (Dog->Get_Health() <= 0)
		Dog->ResetLevel();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("HP: %i"), Dog->Get_Health()));
}

void AHotMug_Item::Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog)
{
	Dog->Set_Jump(Change_Jump);
	Dog->Set_Step(Change_Step);
	Dog->Set_Gravity(Change_Gravity);
	FJumpDelegate.BindUObject(this, &AHotMug_Item::Deactivate_Jump_Effects, Dog);
	GetWorld()->GetTimerManager().SetTimer(FJumpTimer, FJumpDelegate, 15.0f, false);
}

void AHotMug_Item::Deactivate_Jump_Effects(ADog* Dog)
{
	Dog->Set_Jump(420.0f);
	Dog->Set_Step(45.0f);
	Dog->Set_Gravity(1.0f);
}

void AHotMug_Item::Change_Seed(float Change, ADog* Dog)
{
	Dog->Set_Walk(Change);
	FSpeedDelegate.BindUObject(this, &AHotMug_Item::Reset_speed, Dog);
	GetWorld()->GetTimerManager().SetTimer(FSpeedTimer, FSpeedDelegate, 15.0f, false);
}

void AHotMug_Item::Reset_speed(ADog* Dog)
{
	Dog->Set_Walk(600.0f);
	Destroy();
}