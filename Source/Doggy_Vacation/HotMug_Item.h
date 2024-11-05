// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Interface.h"
#include "Parent_Item.h"
#include "HotMug_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API AHotMug_Item : public AParent_Item, public IDamage_Interface
{
	GENERATED_BODY()
	
public:
	AHotMug_Item() {
		IScore = -50;
	}

	virtual void TakeDamage(int Damage) override;
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere) int Attack = 50;
};
