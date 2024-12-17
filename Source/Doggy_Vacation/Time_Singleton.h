// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Time_Singleton.generated.h"


UCLASS()
class DOGGY_VACATION_API UTime_Singleton : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UTime_Singleton();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION()
	void Add_Time(float Change);

	UFUNCTION()
	int Get_Time();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clock")
	float Time;

	UPROPERTY()
	FTimerHandle FRoundTimer;

	UFUNCTION()
	void Restart();
};
