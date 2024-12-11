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

	virtual void TakeDamage(int Damage, int& HP) override;

	virtual void Time_Changer(float Change, int& Time) override;

	UPROPERTY(EditAnywhere) 
	int Time_Change;
	
	UPROPERTY() 
	int Heal;
};
