// Fill out your copyright notice in the Description page of Project Settings.


#include "Steak_Item.h"
#include "Dog.h"

ASteak_Item::ASteak_Item()
{
	IScore = 75;
	Heal = 50;
}

void ASteak_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog && Dog == OtherActor) {
		Dog->Set_Score(IScore);
		Dog->Add_Item(this);
		Spawn_Item();
		IDamage_Interface::TakeDamage(Heal, Dog->Health);
		Destroy();
	}
}
