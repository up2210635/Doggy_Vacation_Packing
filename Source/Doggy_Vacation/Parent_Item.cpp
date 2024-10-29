// Fill out your copyright notice in the Description page of Project Settings.


#include "Parent_Item.h"
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

	IScore = 50;
}

// Called when the game starts or when spawned
void AParent_Item::BeginPlay()
{
	Super::BeginPlay();

	Dog = Cast<ADog>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AParent_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParent_Item::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Dog && Dog == OtherActor) {
		Dog->Set_Score(IScore);
		Destroy();
	}
}