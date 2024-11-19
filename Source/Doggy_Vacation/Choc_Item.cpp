// Fill out your copyright notice in the Description page of Project Settings.


#include "Choc_Item.h"
#include "Dog.h"

void AChoc_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog && Dog == OtherActor) {
		Dog->Set_Score(IScore);
		Dog->Add_Item(this);
		Spawn_Item();
		IDamage_Interface::TakeDamage(Attack, Dog->Health);
		if (Dog->Health <= 0) {
			Dog->ResetLevel();
		}
		Destroy();
	}
}