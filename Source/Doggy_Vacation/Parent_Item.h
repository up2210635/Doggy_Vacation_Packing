// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enum_Items.h"
#include "GameFramework/Actor.h"
#include "Parent_Item.generated.h"

UCLASS()
class DOGGY_VACATION_API AParent_Item : public AActor, public Enum_Items
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AParent_Item();

	UPROPERTY(EditAnywhere, Category = "Values") 
	int IScore;
	UPROPERTY(EditDefaultsOnly, Category = "Spawning") 
	TSubclassOf<AParent_Item> Actors;
	UPROPERTY(EditAnywhere)
	int Spawn_Index;
	UPROPERTY()
	AActor* Ptr;
	UPROPERTY()
	FVector Location;
	UPROPERTY()
	FRotator Angle = FRotator::ZeroRotator;

	UFUNCTION()
	void Initialise();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION() 
	virtual void Pick_Up();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;

	UFUNCTION() 
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};