// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "ChildsBlanket_Item.generated.h"

class ADog;

UCLASS()
class DOGGY_VACATION_API AChildsBlanket_Item : public AParent_Item
{
	GENERATED_BODY()
	
public:
	AChildsBlanket_Item();

	virtual void Pick_Up() override;

protected:

	UPROPERTY(EditAnywhere)
	int Time_Change;

	UFUNCTION()
	void Time_Changer(float Change, ADog* Dog);
};
