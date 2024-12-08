// Fill out your copyright notice in the Description page of Project Settings.

#include "Dog.h"
#include "Time_Interface.h"

// Add default functionality here for any ITime_Interface functions that are not pure virtual.

void ITime_Interface::Time_Changer(float Change, int& Time)
{
	Time += Change;
}
