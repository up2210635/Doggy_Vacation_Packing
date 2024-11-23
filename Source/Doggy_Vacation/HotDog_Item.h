// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "HotDog_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API AHotDog_Item : public AParent_Item
{
	GENERATED_BODY()
	
public:
	AHotDog_Item() {
		IScore = 10;
	}
};
