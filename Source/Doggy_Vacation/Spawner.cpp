// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Parent_Item.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AParent_Item> ItemClassAsset(TEXT("/Game/Blueprints/Good_Items/BP_TeddyBear_Item"));
	if (ItemClassAsset.Succeeded())
	{
		DefaultItemClass = ItemClassAsset.Class;
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Things are fucked"));
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Spawn_Start();
}

void ASpawner::Spawn_Start()
{
	srand(time(0));

	UWorld* World = GetWorld();
	World->SpawnActor<AParent_Item>(DefaultItemClass, FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
}

float ASpawner::CoinFlip(int Add, int Sides)
{
	return (Add + (FMath::Rand() % Sides));
}