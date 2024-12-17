// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Interface.h"
#include "Parent_Item.h"
#include "Steak_Item.generated.h"

class ADog;
UCLASS()
class DOGGY_VACATION_API ASteak_Item : public AParent_Item, public IDamage_Interface
{
	GENERATED_BODY()
	
public:
	ASteak_Item();
	
	virtual void Pick_Up() override;

	virtual void TakeDamage(int Damage, ADog* Dog) override;

protected:

	UPROPERTY(EditAnywhere) 
	float Time_Change;
	
	UPROPERTY() 
	int Heal;

	UFUNCTION()
	void Time_Changer(float Change, ADog* Dog);
};
