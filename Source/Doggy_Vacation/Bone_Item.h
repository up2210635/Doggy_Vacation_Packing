// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "Speed_Interface.h"
#include "Bone_Item.generated.h"

class ADog;

UCLASS()
class DOGGY_VACATION_API ABone_Item : public AParent_Item, public ISpeed_Interface
{
	GENERATED_BODY()
	
public:
	ABone_Item();

	virtual void Pick_Up() override;

	virtual void Change_Seed(float Change, ADog* Dog) override;

	virtual void Undo_Seed_Effects(float Walk, ADog* Dog) override;

protected:

	UPROPERTY(EditAnywhere)
	float New_Walk;

	FTimerHandle FSpeedTimer;

	FTimerDelegate FSpeedDelegate;
};
