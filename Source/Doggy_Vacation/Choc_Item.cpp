// Fill out your copyright notice in the Description page of Project Settings.


#include "Choc_Item.h"

void AChoc_Item::TakeDamage(int Damage)
{
	Dog->Health -= Damage;
}

void AChoc_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Dog && Dog == OtherActor) {
		Dog->Set_Score(IScore);
		TakeDamage(Attack);
		Destroy();
	}
}