// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "Jump_Interface.h"
#include "ChewToy_Item.generated.h"

class ADog;

UCLASS()
class DOGGY_VACATION_API AChewToy_Item : public AParent_Item, public IJump_Interface
{
	GENERATED_BODY()
	
public: 
	AChewToy_Item();

	virtual void Pick_Up() override;

	virtual void Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog) override;

	virtual void Undo_Jump_Effects(float Jump, float Step, float Gravity, ADog* Dog) override;

protected:

	UPROPERTY()
	float New_Jump;
	UPROPERTY()
	float New_Step;
	UPROPERTY()
	float New_Gravity;

	FTimerHandle FJumpTimer;

	FTimerDelegate FJumpDelegate;
};