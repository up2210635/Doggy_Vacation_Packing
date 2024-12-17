// Fill out your copyright notice in the Description page of Project Settings.


#include "Choc_Item.h"
#include "Dog.h"
#include "Spawner.h"

AChoc_Item::AChoc_Item()
{
	IScore = -50;
	Attack = -75;
	Spawn_Index = BP_Choc_Item;
	New_Jump    = 210.0f;
	New_Step    = 25.0f;
	New_Gravity = 0.75f;
	New_Walk    = 450.0f;
}

void AChoc_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Dog && Dog == Ptr && Spawn) 
	{
		Dog->Add_Score(IScore);
		Spawn->Repeat_Spawn(Spawn_Index);
		TakeDamage(Attack, Dog);
		Activate_Jump_Effects(New_Jump, New_Step, New_Gravity, Dog);
		Change_Seed(New_Walk, Dog);
		Disable(this);
	}
}

void AChoc_Item::TakeDamage(int Damage, ADog* Dog)
{
	Dog->Add_Health(Damage);
	if (Dog->Get_Health() <= 0)
		Dog->ResetLevel();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("HP: %i"), Dog->Get_Health()));
}

void AChoc_Item::Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog)
{
	Dog->Subtract_Jump(Change_Jump);
	Dog->Subtract_Step(Change_Step);
	Dog->Subtract_Gravity(Change_Gravity);
	FJumpDelegate.BindUObject(this, &AChoc_Item::Undo_Jump_Effects, New_Jump, New_Step, New_Gravity, Dog);
	GetWorld()->GetTimerManager().SetTimer(FJumpTimer, FJumpDelegate, 15.0f, false);
}

void AChoc_Item::Undo_Jump_Effects(float Jump, float Step, float Gravity, ADog* Dog)
{
	Dog->Add_Jump(Jump);
	Dog->Add_Step(Step);
	Dog->Add_Gravity(Gravity);
}

void AChoc_Item::Change_Seed(float Change, ADog* Dog)
{
	Dog->Subtract_Walk(Change);
	FSpeedDelegate.BindUObject(this, &AChoc_Item::Undo_Seed_Effects, New_Walk, Dog);
	GetWorld()->GetTimerManager().SetTimer(FSpeedTimer, FSpeedDelegate, 15.0f, false);
}

void AChoc_Item::Undo_Seed_Effects(float Walk, ADog* Dog)
{
	Dog->Add_Walk(Walk);
	Destroy();
}