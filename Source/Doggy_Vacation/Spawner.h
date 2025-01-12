// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enum_Items.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AParent_Item;

UCLASS()
class DOGGY_VACATION_API ASpawner : public AActor, public Enum_Items
{
	GENERATED_BODY()

public:	
	ASpawner();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Spawn_Start();
	UFUNCTION()
	void Spawn_Item(TSubclassOf<AParent_Item> Item_Class, AParent_Item* Item_ptr, FVector Location);
	UFUNCTION()
	void Repeat_Spawn(int Item);
	UFUNCTION()
	float CoinFlip(int Add, int Sides);
	UFUNCTION()
	TSubclassOf<AParent_Item> Get_Name(int Index);

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