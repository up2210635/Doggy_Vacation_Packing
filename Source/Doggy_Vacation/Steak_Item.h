// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Interface.h"
#include "Time_Interface.h"
#include "Parent_Item.h"
#include "Steak_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API ASteak_Item : public AParent_Item, public IDamage_Interface, public ITime_Interface
{
	GENERATED_BODY()
	
public:
	ASteak_Item();
	
	virtual void Pick_Up();
	
	UFUNCTION()
	void Reset_Effects();

	UPROPERTY(EditAnywhere) 
	int Time = 10;
	
	UPROPERTY() 
	int Heal;

	UPROPERTY()
	FTimerHandle FEffectsTimer;
};
