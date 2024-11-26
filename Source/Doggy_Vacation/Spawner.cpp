// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Parent_Item.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

void ASpawner::Spawn_Start()
{
	ConstructorHelpers::FClassFinder<APawn> ItemClassFinder(TEXT("/All/Game/Blueprints/Good_Items/BP_TeddyBear_Item"));
	
	srand(time(0));

	UWorld* World = GetWorld();
	World->SpawnActor<AParent_Item>(ItemClassFinder.Class, FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
}

float ASpawner::CoinFlip(int Add, int Sides)
{
	return (Add + (FMath::Rand() % Sides));
}