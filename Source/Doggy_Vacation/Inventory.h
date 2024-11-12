// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"

class AParent_Item;

UCLASS()
class DOGGY_VACATION_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventory();

	void Set_Item(AParent_Item* Change) {
		Items = Change;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
 
	//UPROPERTY(EditDefaultsOnly) TArray<int> Items;
	UPROPERTY(EditDefaultsOnly) AParent_Item* Items;
};
