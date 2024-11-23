// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "TeddyBear_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API ATeddyBear_Item : public AParent_Item
{
	GENERATED_BODY()
	
public:
	ATeddyBear_Item() {
		IScore = 100;
	}
};
