// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Speed_Interface.generated.h"

class ADog;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USpeed_Interface : public UInterface
{
	GENERATED_BODY()
};

class DOGGY_VACATION_API ISpeed_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Change_Seed(float Change, ADog* Dog) = 0;


	virtual void Reset_speed(ADog* Dog) = 0;
};
