// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "DogJacket_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API ADogJacket_Item : public AParent_Item
{
	GENERATED_BODY()
	
public:
	ADogJacket_Item() {
		IScore = 20;
	}
};
