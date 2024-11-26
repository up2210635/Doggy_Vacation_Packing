// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AParent_Item;

UCLASS()
class DOGGY_VACATION_API ASpawner : public AActor
{
	GENERATED_BODY()

public:	
	ASpawner();

	virtual void Tick(float DeltaTime) override;

	void Spawn_Start();
	float CoinFlip(int Add, int Sides);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AParent_Item> DefaultItemClass;
};
