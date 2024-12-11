// Fill out your copyright notice in the Description page of Project Settings.


#include "kennel.h"
#include "Dog.h"
#include "Spawner.h"
#include "Parent_Item.h"
#include "Components/BoxComPonent.h"

// Sets default values
Akennel::Akennel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	KennelBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	KennelBox->SetBoxExtent(FVector(20.f, 20.f, 20.f));
	RootComponent = KennelBox;

	KennelBox->OnComponentBeginOverlap.AddDynamic(this, &Akennel::OnOverLapBegin);
	KennelBox->OnComponentEndOverlap.AddDynamic(this, &Akennel::OnOverLapEnd);

	InBox = false;
}

// Called when the game starts or when spawned
void Akennel::BeginPlay()
{
	Super::BeginPlay();
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	Dog->OnInteract.AddDynamic(this,&Akennel::Place_Item);
}

// Called every frame
void Akennel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Akennel::Place_Item()
{
	if (InBox == true)
	{
		ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (Dog && Dog == Ptr)
		{
			ASpawner* Spawn = Cast<ASpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ASpawner::StaticClass()));
			if (Dog->Holding == true && Spawn)
			{
				FVector Location = GetActorLocation() + FVector(-300, 0, 0);
				Spawn->Spawn_Item(Dog->Get_Items(), Location);
				Dog->Holding = false;
			}
			else
				UE_LOG(LogTemp, Error, TEXT("Holding and Spawn failed"));
		}
		else
			UE_LOG(LogTemp, Error, TEXT("dog cast failed"));
	}
}

void Akennel::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Ptr = OtherActor;
	InBox = true;
}

void Akennel::OnOverLapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Ptr = OtherActor;
	InBox = false;
}