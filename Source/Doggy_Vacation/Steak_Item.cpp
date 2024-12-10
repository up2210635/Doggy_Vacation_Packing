// Fill out your copyright notice in the Description page of Project Settings.


#include "Steak_Item.h"
#include "Dog.h"
#include "GameFramework/CharacterMovementComponent.h"

ASteak_Item::ASteak_Item()
{
	IScore = 75;
	Heal = 50;
	Spawn_Index = BP_Steak_Item;
}

void ASteak_Item::Pick_Up()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog && Dog == Ptr)
	{
		Dog->Set_Score(IScore);
		IDamage_Interface::TakeDamage(Heal, Dog->Health);
		ITime_Interface::Time_Changer(Time, Dog->Time);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("____________"));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Time: %i"), Dog->Time));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("HP: %i"), Dog->Health));
		}
		Dog->GetCharacterMovement()->JumpZVelocity = 840.0f;
		GetWorld()->GetTimerManager().SetTimer(FEffectsTimer, this, &ASteak_Item::Reset_Effects, 1.0f, false);
		Destroy();
	}
}

void ASteak_Item::Reset_Effects()
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog)
	{
		Dog->GetCharacterMovement()->JumpZVelocity = 420.0f;
	}
}
