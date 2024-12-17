// Fill out your copyright notice in the Description page of Project Settings.


#include "Time_Singleton.h"
#include <Kismet\GameplayStatics.h>

UTime_Singleton::UTime_Singleton()
{
	Time = 120.0f;
}

void UTime_Singleton::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Warning, TEXT("Initialize of UTime_Singleton"));

	GetWorld()->GetTimerManager().SetTimer(FRoundTimer, this, &UTime_Singleton::Restart, Time, false);
}

void UTime_Singleton::Deinitialize()
{
	Super::Deinitialize();

	UE_LOG(LogTemp, Warning, TEXT("Deinitialize of UTime_Singleton"));
}

void UTime_Singleton::Add_Time(float Change)
{
	float New_Time = GetWorld()->GetTimerManager().GetTimerRemaining(FRoundTimer) + Change;
	GetWorld()->GetTimerManager().ClearTimer(FRoundTimer);
	GetWorld()->GetTimerManager().SetTimer(FRoundTimer, this, &UTime_Singleton::Restart, New_Time, false);
}

int UTime_Singleton::Get_Time()
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(FRoundTimer);
}

void UTime_Singleton::Restart()
{
	GetWorld()->GetTimerManager().ClearTimer(FRoundTimer);
	GetWorld()->GetTimerManager().SetTimer(FRoundTimer, this, &UTime_Singleton::Restart, Time, false);
	if (GEngine)
		GEngine->ClearOnScreenDebugMessages();
	FName(FirstPersonMap) = *GetWorld()->GetName();
	UGameplayStatics::OpenLevel(GetWorld(), FirstPersonMap);
}