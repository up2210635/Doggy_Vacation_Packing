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

	// Basic character ints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") 
	int PScore;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = "Values") 
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") 
	int Time_Remaining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") 
	int Time;

	// Character movement properties
	UPROPERTY(EditAnywhere)
	float Jump_Velocity;
	UPROPERTY(EditAnywhere)
	float Walk_Speed;
	UPROPERTY(EditAnywhere)
	float Walk_Crouched;
	UPROPERTY(EditAnywhere)
	float Step_Height;
	UPROPERTY(EditAnywhere)
	float Gravity;

	// other character properties
	UPROPERTY() 
	bool Holding;

	UPROPERTY(EditAnywhere, BlueprintreadWrite) 
	TArray<AParent_Item*> Inventory;

	UPROPERTY(BlueprintAssignable)
	FOnInteract OnInteract;

	UPROPERTY()
	FTimerHandle FRoundTime;

	// Set functions
	UFUNCTION()
	void Set_Score(int Change);
	UFUNCTION()
	void Set_Jump();
	UFUNCTION()
	void Set_Walk();
	UFUNCTION()
	void Set_Crouched();
	UFUNCTION()
	void Set_Step();
	UFUNCTION()
	void Set_Gravity();

	// Get function
	UFUNCTION()
	TSubclassOf<AParent_Item> Get_Items_Class();
	UFUNCTION()
	AParent_Item* Get_Item_ptr();
	UFUNCTION()
	float Get_Time();

	// Other funtion
	UFUNCTION()
	void ResetLevel();
	UFUNCTION()
	void Add_Item(AParent_Item* Actor);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

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

	UPROPERTY() 
	bool Jumping;
};