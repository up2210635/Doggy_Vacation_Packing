// Fill out your copyright notice in the Description page of Project Settings.


#include "Parent_Item.h"
#include "Dog.h"
#include "Spawner.h"
#include "Components/BoxComPonent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AParent_Item::AParent_Item()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(20.f, 20.f, 20.f));
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AParent_Item::OnOverLapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AParent_Item::OnOverLapEnd);

	IScore = 50;
}

void AParent_Item::Spawn_Item() {

	srand(time(0));

	UWorld* World = GetWorld();
	World->SpawnActor<AParent_Item>(Actors, FVector(CoinFlip(150, 2701), CoinFlip(1950, 1401), CoinFlip(50, 301)), FRotator::ZeroRotator);
}

// Called when the game starts or when spawned
void AParent_Item::BeginPlay()
{
	Super::BeginPlay();
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	Dog->OnSpawn.AddDynamic(this,&AParent_Item::Pick_Up);
}

 float AParent_Item::CoinFlip(int Add, int Sides)
{
	return (Add + (FMath::Rand() % Sides));
}

void AParent_Item::Pick_Up()
{
	if (InBox == true)
	{
		ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (Dog && Dog == Ptr) {
			Dog->Set_Score(IScore);
			Dog->Add_Item(this);
			Spawn_Item();
			Destroy();
		}
	}
}

// Called every frame
void AParent_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParent_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	InBox = true;
	Ptr = OtherActor;
}

void AParent_Item::OnOverLapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	InBox = false;
	Ptr = OtherActor;
}
