// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum EAll_Items
{
	BP_TeddyBear_Item, BP_Bone_Item, BP_Steak_Item, BP_ChewToy_Item, BP_ChildsBlanket_Item, BP_Frisby_Item, BP_DogJacket_Item, BP_HotDog_Item, BP_BeachBall_Item,
	BP_Bag_Item, BP_Choc_Item, BP_Phone_Item, BP_Shoes_Item, BP_DogBed_Item, BP_Mug_Item
};

class DOGGY_VACATION_API Enum_Items
{
public:
	Enum_Items();
	~Enum_Items();
};
