// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Dog.generated.h"

UCLASS()
class DOGGY_VACATION_API ADog : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADog();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values") int PScore{};
	UPROPERTY(EditAnywhere, BLueprintreadWrite, Category = "Values") int Health = 100;

	void Set_Score(int Change) {
		PScore += Change;
	}
	void ResetLevel() {
		FName(FirstPersonMap) = *GetWorld()->GetName();
		UGameplayStatics::OpenLevel(GetWorld(), FirstPersonMap);
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	void MoveForward(float AxisVal);
	void MoveRight(float AxisVal);
	void CheckJump();

	UPROPERTY() bool Jumping;
};