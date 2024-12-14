// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enum_Items.h"
#include "GameFramework/Actor.h"
#include "Fetch_List.generated.h"

UCLASS()
class DOGGY_VACATION_API AFetch_List : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFetch_List();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Check_List(int Item);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int List_Size;

	UPROPERTY(EditAnywhere)
	TArray<int> List;

	UPROPERTY(EditAnywhere)
	TArray<int> Mark_Sheet;

	UFUNCTION()
	void Create_List();

	UFUNCTION()
	int Rand_Item();
};