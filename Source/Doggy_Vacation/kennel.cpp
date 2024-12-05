// Fill out your copyright notice in the Description page of Project Settings.


#include "kennel.h"
#include "Dog.h"
#include "Spawner.h"
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
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hello World"));
}

void Akennel::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADog* Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Dog && Dog == OtherActor) 
	{
		if (Dog->Holding == true) 
		{
			Dog->Holding = false;
		}
	}
}
