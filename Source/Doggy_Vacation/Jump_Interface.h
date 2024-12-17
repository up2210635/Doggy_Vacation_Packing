// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Jump_Interface.generated.h"

class ADog;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UJump_Interface : public UInterface
{
	GENERATED_BODY()
};

class DOGGY_VACATION_API IJump_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Activate_Jump_Effects(float Change_Jump, float Change_Step, float Change_Gravity, ADog* Dog) = 0;

	virtual void Undo_Jump_Effects(float Jump, float Step, float Gravity, ADog* Dog) = 0;
};
