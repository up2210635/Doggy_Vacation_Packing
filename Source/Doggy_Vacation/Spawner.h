// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AParent_Item;

UENUM()
enum Enum_Items
{
	BP_TeddyBear_Item, BP_Bone_Item, BP_Steak_Item, BP_ChewToy_Item, BP_ChildsBlanket_Item, BP_Frisby_Item, BP_DogJacket_Item, BP_HotDog_Item, BP_BeachBall_Item,
	BP_Bag_Item, BP_Choc_Item, BP_Phone_Item, BP_Shoes_Item, BP_DogBed_Item, BP_Mug_Item
};

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
	void Repeat_Spawn(int Item);
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