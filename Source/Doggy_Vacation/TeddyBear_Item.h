// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Time_Interface.h"
#include "Parent_Item.h"
#include "TeddyBear_Item.generated.h"

class ADog;

UCLASS()
class DOGGY_VACATION_API ATeddyBear_Item : public AParent_Item, public ITime_Interface
{
	GENERATED_BODY()
	
public:
	ATeddyBear_Item();

	virtual void Pick_Up() override;

	virtual void Time_Changer(float Change, ADog* Dog) override;

protected:

	UPROPERTY(EditAnywhere)
	int Time_Change;
};
