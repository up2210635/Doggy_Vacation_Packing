// Fill out your copyright notice in the Description page of Project Settings.


#include "Steak_Item.h"

void ASteak_Item::TakeDamage(int Damage)
{
	Dog->Health += Damage;
}

void ASteak_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Dog && Dog == OtherActor) {
		Dog->Set_Score(IScore);
		TakeDamage(Heal);
		Destroy();
	}
}
