// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Parent_Item.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Adresses = { "/Game/Blueprints/Good_Items/BP_TeddyBear_Item",   "/Game/Blueprints/Good_Items/BP_Bone_Item",          "/Game/Blueprints/Good_Items/BP_Steak_Item", 
				 "/Game/Blueprints/Good_Items/BP_ChewToy_Item",     "/Game/Blueprints/Good_Items/BP_ChildsBlanket_Item", "/Game/Blueprints/Normal_Items/BP_Frisby_Item", 
			     "/Game/Blueprints/Normal_Items/BP_DogJacket_Item", "/Game/Blueprints/Normal_Items/BP_HotDog_Item",      "/Game/Blueprints/Normal_Items/BP_BeachBall_Item",
				 "/Game/Blueprints/Normal_Items/BP_Bag_Item",       "/Game/Blueprints/Bad_Items/BP_Choc_Item",           "/Game/Blueprints/Bad_Items/BP_Phone_Item", 
				 "/Game/Blueprints/Bad_Items/BP_Shoes_Item",        "/Game/Blueprints/Bad_Items/BP_DogBed_Item",         "/Game/Blueprints/Bad_Items/BP_Mug_Item" };

	for (int i{}; i < Adresses.Num(); i++)
	{
		ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder(*Adresses[i]);
		Add_Class(ItemClassFinder);
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	Spawn_Start();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::Spawn_Start()
{
	srand(time(nullptr));

	for (int i{}; i < Classes.Num(); i++)
	{
		GetWorld()->SpawnActor<AParent_Item>(Classes[i], FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
	}
}

void ASpawner::Spawn_Item(TSubclassOf<AParent_Item> Item_Class, FVector Location)
{
	AParent_Item* Test = GetWorld()->SpawnActor<AParent_Item>(Item_Class, Location, FRotator::ZeroRotator);

	if (Test) 
	{
		Test->Initialise();
	}
}

void ASpawner::Repeat_Spawn(int Spawn_Index)
{
	int Class_Index;
	if (Spawn_Index >= BP_TeddyBear_Item && Spawn_Index <= BP_ChildsBlanket_Item)
		Class_Index = FMath::Rand() % 5;
	else if (Spawn_Index >= BP_Frisby_Item && Spawn_Index <= BP_Bag_Item)
		Class_Index = (FMath::Rand() % 5) + 5;
	else
		Class_Index = (FMath::Rand() % 5) + 10;
	GetWorld()->SpawnActor<AParent_Item>(Classes[Class_Index], FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
}

float ASpawner::CoinFlip(int Add, int Sides)
{
	return (Add + (FMath::Rand() % Sides));
}

void ASpawner::Add_Class(ConstructorHelpers::FClassFinder<AParent_Item> ItemClass)
{
	if (ItemClass.Succeeded())
	{
		DefaultItemClass = ItemClass.Class;
		Classes.Add(DefaultItemClass);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ItemClass did not succeed"));
	}
}