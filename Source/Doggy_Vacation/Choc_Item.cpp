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
		TakeDamage(Attack, Dog);
		Activate_Jump_Effects(210.0f, 20.0f, 0.25f, Dog);
		Change_Seed(150.0f, Dog);
		Disable(this);
	}
}

void AChoc_Item::TakeDamage(int Damage, ADog* Dog)
{
	Dog->Health += Damage;
	if (Dog->Health <= 0)
		Dog->ResetLevel();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("HP: %i"), Dog->Health));
}

void AChoc_Item::Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog)
{
	Dog->Jump_Velocity = Change_Jump;
	Dog->Step_Height = Change_Step;
	Dog->Gravity = Change_Gravity;
	Dog->Set_Jump();
	Dog->Set_Step();
	Dog->Set_Gravity();
	FJumpDelegate.BindUObject(this, &AChoc_Item::Deactivate_Jump_Effects, Dog);
	GetWorld()->GetTimerManager().SetTimer(FJumpTimer, FJumpDelegate, 15.0f, false);
}

void AChoc_Item::Deactivate_Jump_Effects(ADog* Dog)
{
	Dog->Jump_Velocity = 420.0f;
	Dog->Step_Height = 45.0f;
	Dog->Gravity = 1.0f;
	Dog->Set_Jump();
	Dog->Set_Step();
	Dog->Set_Gravity();
}

void AChoc_Item::Change_Seed(float Change, ADog* Dog)
{
	Dog->Walk_Speed = Change;
	Dog->Set_Walk();
	FSpeedDelegate.BindUObject(this, &AChoc_Item::Reset_speed, Dog);
	GetWorld()->GetTimerManager().SetTimer(FSpeedTimer, FSpeedDelegate, 15.0f, false);
}

void AChoc_Item::Reset_speed(ADog* Dog)
{
	Dog->Walk_Speed = 600.0f;
	Dog->Set_Walk();
	Destroy();
}