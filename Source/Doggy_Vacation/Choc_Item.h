// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Interface.h"
#include "Jump_Interface.h"
#include "Speed_Interface.h"
#include "Parent_Item.h"
#include "Choc_Item.generated.h"

class ADog;

UCLASS()
class DOGGY_VACATION_API AChoc_Item : public AParent_Item, public IDamage_Interface, public IJump_Interface, public ISpeed_Interface
{
	GENERATED_BODY()

public:
	AChoc_Item();

	virtual void Pick_Up() override;

	virtual void TakeDamage(int Damage, ADog* Dog) override;

	virtual void Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog) override;

	virtual void Deactivate_Jump_Effects(ADog* Dog) override;

	virtual void Change_Seed(float Change, ADog* Dog) override;

	virtual void Reset_speed(ADog* Dog) override;

protected:

	UPROPERTY(EditAnywhere) 
	int Attack;

	UPROPERTY()
	float New_Jump;
	UPROPERTY()
	float New_Step;
	UPROPERTY()
	float New_Gravity;
	UPROPERTY()
	float New_Walk;

	FTimerHandle FJumpTimer;
	FTimerHandle FSpeedTimer;

	FTimerDelegate FJumpDelegate;
	FTimerDelegate FSpeedDelegate;
};