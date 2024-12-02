// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Parent_Item.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassFinder(TEXT("/Game/Blueprints/Good_Items/BP_TeddyBear_Item"));
	Add_Class(ItemClassFinder);
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

	UWorld* World = GetWorld();
	World->SpawnActor<AParent_Item>(Classes[Index], FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
}

float ASpawner::CoinFlip(int Add, int Sides)
{
	return (Add + (FMath::Rand() % Sides));
}

void ASpawner::Add_Class(ConstructorHelpers::FClassFinder<AParent_Item> ItemClass)
{
	if (ItemClass.Succeeded())
	{
		Index++;
		DefaultItemClass = ItemClass.Class;
		Classes.Add(DefaultItemClass);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Things are fucked"));
	}
}
