 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "kennel.generated.h"

/*enum Enum_Items
{
	BP_TeddyBear_Item, BP_Bone_Item, BP_Steak_Item, BP_ChewToy_Item, BP_ChildsBlanket_Item, BP_Frisby_Item, BP_DogJacket_Item, BP_HotDog_Item, BP_BeachBall_Item, BP_Bag_Item, 
	BP_Choc_Item, BP_Phone_Item, BP_Shoes_Item, BP_DogBed_Item, BP_Mug_Item
};*/

UCLASS()
class DOGGY_VACATION_API Akennel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Akennel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* KennelBox;
	UPROPERTY()
	AActor* Ptr;
	UPROPERTY() 
	bool InBox;

	UFUNCTION()
	void Place_Item();

	UFUNCTION()
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverLapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
