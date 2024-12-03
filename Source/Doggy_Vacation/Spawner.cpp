// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Parent_Item.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder1(TEXT("/Game/Blueprints/Good_Items/BP_TeddyBear_Item"));
	Add_Class(ItemClassFinder1);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder2(TEXT("/Game/Blueprints/Good_Items/BP_Bone_Item"));
	Add_Class(ItemClassFinder2);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder3(TEXT("/Game/Blueprints/Good_Items/BP_Steak_Item"));
	Add_Class(ItemClassFinder3);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder4(TEXT("/Game/Blueprints/Good_Items/BP_ChewToy_Item"));
	Add_Class(ItemClassFinder4);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder5(TEXT("/Game/Blueprints/Good_Items/BP_ChildsBlanket_Item"));
	Add_Class(ItemClassFinder5);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder6(TEXT("/Game/Blueprints/Normal_Items/BP_Frisby_Item"));
	Add_Class(ItemClassFinder6);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder7(TEXT("/Game/Blueprints/Normal_Items/BP_DogJacket_Item"));
	Add_Class(ItemClassFinder7);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder8(TEXT("/Game/Blueprints/Normal_Items/BP_HotDog_Item"));
	Add_Class(ItemClassFinder8);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder9(TEXT("/Game/Blueprints/Normal_Items/BP_BeachBall_Item"));
	Add_Class(ItemClassFinder9);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder10(TEXT("/Game/Blueprints/Normal_Items/BP_Bag_Item"));
	Add_Class(ItemClassFinder10);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder11(TEXT("/Game/Blueprints/Bad_Items/BP_Choc_Item"));
	Add_Class(ItemClassFinder11);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder12(TEXT("/Game/Blueprints/Bad_Items/BP_Phone_Item"));
	Add_Class(ItemClassFinder12);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder13(TEXT("/Game/Blueprints/Bad_Items/BP_Shoes_Item"));
	Add_Class(ItemClassFinder13);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder14(TEXT("/Game/Blueprints/Bad_Items/BP_DogBed_Item"));
	Add_Class(ItemClassFinder14);
	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder15(TEXT("/Game/Blueprints/Bad_Items/BP_Mug_Item"));
	Add_Class(ItemClassFinder15);
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
	srand(time(0));
	Length = Classes.Num();

	for (int i{}; i < Length; i++)
	{
		UWorld* World = GetWorld();
		World->SpawnActor<AParent_Item>(Classes[i], FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
	}
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
		UE_LOG(LogTemp, Error, TEXT("Things are fucked"));
	}
}
