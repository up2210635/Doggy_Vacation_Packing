// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "DogBed_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API ADogBed_Item : public AParent_Item
{
	GENERATED_BODY()
	
public:
	ADogBed_Item() {
		IScore = -10;
	}
};
