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

	// Add functions
	UFUNCTION()
	void Add_Score(int Change);
	UFUNCTION()
	void Add_Jump(int Change);
	UFUNCTION()
	void Add_Walk(int Change);
	UFUNCTION()
	void Add_Step(int Change);
	UFUNCTION()
	void Add_Gravity(int Change);
	UFUNCTION()
	void Add_Item(AParent_Item* Actor);
	UFUNCTION()
	void Add_Health(int Change);

	// Subtract functions
	UFUNCTION()
	void Subtract_Jump(int Change);
	UFUNCTION()
	void Subtract_Walk(int Change);
	UFUNCTION()
	void Subtract_Step(int Change);
	UFUNCTION()
	void Subtract_Gravity(int Change);

	// Get function
	UFUNCTION()
	TSubclassOf<AParent_Item> Get_Items_Class();
	UFUNCTION()
	AParent_Item* Get_Item_ptr();
	UFUNCTION()
	bool Get_Holding();
	UFUNCTION()
	int Get_Health();

	// Set functions
	UFUNCTION()
	void Set_Holding(bool change);
	UFUNCTION()
	void Set_Health(int Change);

	// runs when time == 0 || Health == 0
	UFUNCTION()
	void ResetLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Basic character ints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	int PScore;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = "Values")
	int Health;

	// character movement checks
	UPROPERTY()
	bool Jumping;
	UPROPERTY()
	bool Holding;
	UPROPERTY()
	bool Walking;

	// Other Properties
	UPROPERTY()
	FTimerHandle FWalkTimer;
	UPROPERTY(EditAnywhere)
	USoundBase* Wood_spteps;
	UPROPERTY(EditAnywhere, BlueprintreadWrite)
	TArray<AParent_Item*> Inventory;

	// Movement function
	UFUNCTION()
	void CheckStep();
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
	void Walk_Sound();
	UFUNCTION()
	void Kennel();
};