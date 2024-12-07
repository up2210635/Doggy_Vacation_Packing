// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Parent_Item.generated.h"

UCLASS()
class DOGGY_VACATION_API AParent_Item : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AParent_Item();

	UPROPERTY(EditAnywhere, Category = "Values") int IScore;
	UPROPERTY(EditDefaultsOnly, Category = "Spawning") TSubclassOf<AParent_Item> Actors;
	UPROPERTY()AActor* Ptr;

	FVector Location;
	FRotator Angle = FRotator::ZeroRotator;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float CoinFlip(int Add, int Sides);

	UFUNCTION() void Pick_Up();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;

	UFUNCTION() 
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};