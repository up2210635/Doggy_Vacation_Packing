// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AParent_Item;

/*UENUM()
enum Enum_Items
{
	BP_TeddyBear_Item_C, BP_Bone_Item_C, BP_Steak_Item_C, BP_ChewToy_Item_C, BP_ChildsBlanket_Item_C, BP_Frisby_Item_C, BP_DogJacket_Item_C, BP_HotDog_Item_C, BP_BeachBall_Item_C,
	BP_Bag_Item_C, BP_Choc_Item_C, BP_Phone_Item_C, BP_Shoes_Item_C, BP_DogBed_Item_C, BP_Mug_Item_C, Last
};*/

UCLASS()
class DOGGY_VACATION_API ASpawner : public AActor
{
	GENERATED_BODY()

public:	
	ASpawner();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Spawn_Start();
	UFUNCTION()
	void Spawn_Item(TSubclassOf<AParent_Item> Item, FVector Location);
	UFUNCTION()
	float CoinFlip(int Add, int Sides);

	void Add_Class(ConstructorHelpers::FClassFinder<AParent_Item> ItemClass);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AParent_Item> DefaultItemClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AParent_Item>> Classes;
	UPROPERTY(EditAnywhere) 
	TArray<FString> Adresses;
};