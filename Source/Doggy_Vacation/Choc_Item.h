// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Interface.h"
#include "Parent_Item.h"
#include "Choc_Item.generated.h"

/**
 *
 */
UCLASS()
class DOGGY_VACATION_API AChoc_Item : public AParent_Item, public IDamage_Interface
{
	GENERATED_BODY()

public:
	AChoc_Item();

	virtual void Pick_Up();

	UPROPERTY(EditAnywhere) int Attack;

	virtual void TakeDamage(int Damage, int& HP) override;
};