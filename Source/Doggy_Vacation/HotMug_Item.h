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
	AHotMug_Item();

	virtual void Pick_Up() override;

	virtual void TakeDamage(int Damage, int& HP) override;

	UPROPERTY(EditAnywhere) int Attack;
};
