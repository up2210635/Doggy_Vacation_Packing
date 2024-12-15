// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Dog.generated.h"

class AParent_Item;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS()
class DOGGY_VACATION_API ADog : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADog();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Event Dispatcher
	UPROPERTY(BlueprintAssignable)
	FOnInteract OnInteract;

	// Set functions
	UFUNCTION()
	void Set_Score(int Change);
	UFUNCTION()
	void Set_Jump(int Change);
	UFUNCTION()
	void Set_Walk(int Change);
	UFUNCTION()
	void Set_Step(int Change);
	UFUNCTION()
	void Set_Gravity(int Change);
	UFUNCTION()
	void Set_Holding(bool change);
	UFUNCTION()
	void Set_Time(int Change);
	UFUNCTION()
	void Set_Health(int Change);

	// Get function
	UFUNCTION()
	TSubclassOf<AParent_Item> Get_Items_Class();
	UFUNCTION()
	AParent_Item* Get_Item_ptr();
	UFUNCTION()
	int Get_Time();
	UFUNCTION()
	bool Get_Holding();
	UFUNCTION()
	int Get_Health();

	// Other funtion
	UFUNCTION()
	void ResetLevel();
	UFUNCTION()
	void Add_Item(AParent_Item* Actor);
	UFUNCTION()
	void Add_Health(int Change);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Basic character ints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	int PScore;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = "Values")
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	int Time_Remaining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	int Time;

	// character movement checks
	UPROPERTY()
	bool Jumping;
	UPROPERTY()
	bool Holding;

	// Other propertys
	UPROPERTY(EditAnywhere, BlueprintreadWrite)
	TArray<AParent_Item*> Inventory;
	UPROPERTY()
	FTimerHandle FRoundTime;

	// Movement function
	UFUNCTION()
	void MoveForward(float AxisVal);
	UFUNCTION()
	void MoveRight(float AxisVal);
	UFUNCTION()
	void CheckJump();

	// Print functions
	UFUNCTION()
	void Print_Data();
	UFUNCTION()
	void Print();

	// Other funtion
	UFUNCTION()
	void Kennel();
	UFUNCTION()
	void Counter();
};