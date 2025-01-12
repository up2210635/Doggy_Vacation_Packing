// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damage_Interface.generated.h"

class ADog;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamage_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class DOGGY_VACATION_API IDamage_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION()
	virtual void TakeDamage(int Damage, ADog* Dog) = 0;
};