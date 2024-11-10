// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Interface.h"
#include "Parent_Item.h"
#include "Steak_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API ASteak_Item : public AParent_Item, public IDamage_Interface
{
	GENERATED_BODY()
	
public:
	ASteak_Item() {
		IScore = 75;
	}

	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;


	UPROPERTY(EditAnywhere) int Time = 10;
	UPROPERTY() int Heal = 50;
};
