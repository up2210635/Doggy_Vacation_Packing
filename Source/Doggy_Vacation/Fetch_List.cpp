// Fill out your copyright notice in the Description page of Project Settings.


#include "Fetch_List.h"
#include "Spawner.h"
#include <Kismet\GameplayStatics.h>

// Sets default values
AFetch_List::AFetch_List()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	List_Size = 7;
}

// Called every frame
void AFetch_List::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFetch_List::Check_List(int Item)
{
	if (List.Find(Item) != INDEX_NONE)
	{
		List.RemoveAt(List.Find(Item));
		if (List.IsEmpty() == true)
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 600.0f, FColor::Yellow, TEXT("You Win"));
	}
}

// Called when the game starts or when spawned
void AFetch_List::BeginPlay()
{
	Super::BeginPlay();
	
	Create_List();
}

void AFetch_List::Create_List()
{
	srand(time(0));

	for (int i{}; i < List_Size; i++)
	{
		List.Add(Rand_Item());
	}
	ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
	if (Spawn)
	{
		for (int i{}; i < List_Size; i++)
		{
			FString Name = Spawn->Get_Name(List[i])->GetName();
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 600.0f, FColor::Yellow, (TEXT("Find: %s"), Name));
		}
	}
}

int AFetch_List::Rand_Item()
{
	int Item = FMath::Rand() % 10;
	if (Item == BP_Steak_Item)
		return Rand_Item();
	else
		return Item;
}