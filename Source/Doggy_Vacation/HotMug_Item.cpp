// Fill out your copyright notice in the Description page of Project Settings.


#include "HotMug_Item.h"

void AHotMug_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Dog && Dog == OtherActor) {
		Dog->Set_Score(IScore);
		IDamage_Interface::TakeDamage(Attack, Dog->Health);
		if (Dog->Health <= 0) {
			Dog->ResetLevel();
		}
		Destroy();
	}
}
