// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parent_Item.h"
#include "BeachBall_Item.generated.h"

/**
 * 
 */
UCLASS()
class DOGGY_VACATION_API ABeachBall_Item : public AParent_Item
{
	GENERATED_BODY()
	
public:
	ABeachBall_Item() {
		IScore = 25;
	}
};
