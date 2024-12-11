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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") 
	int PScore{};
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = "Values") 
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") 
	int Time_Remaining{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") 
	int Time;
	// is dog Holding item
	UPROPERTY() 
	bool Holding;
	UPROPERTY(EditAnywhere, BlueprintreadWrite) 
	TArray<AParent_Item*> Inventory;

	UFUNCTION()
	void Set_Score(int Change);
	UFUNCTION()
	void ResetLevel();
	UFUNCTION()
	void Counter();
	UFUNCTION()
	void Add_Item(AParent_Item* Actor);
	UFUNCTION()
	TSubclassOf<AParent_Item> Get_Items_Class();
	UFUNCTION()
	AParent_Item* Get_Item_ptr();
	UFUNCTION()
	float Get_Time();
	UFUNCTION()
	void Jump_Boost();

	UPROPERTY(BlueprintAssignable) 
	FOnInteract OnInteract;
	UPROPERTY()
	FTimerHandle FRoundTime;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UFUNCTION()
	void MoveForward(float AxisVal);
	UFUNCTION()
	void MoveRight(float AxisVal);
	UFUNCTION()
	void CheckJump();
	UFUNCTION()
	void Kennel();
	UFUNCTION()
	void Print_Data();
	UFUNCTION()
	void Print();

	UPROPERTY() 
	bool Jumping;
};