// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Time_Interface.h"
#include "Parent_Item.h"
#include "ChildsBlanket_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API AChildsBlanket_Item : public AParent_Item, public ITime_Interface
{
	GENERATED_BODY()
	
public:
	AChildsBlanket_Item();

	virtual void Pick_Up();

	UPROPERTY(EditAnywhere)
	int Time = 10;
};
