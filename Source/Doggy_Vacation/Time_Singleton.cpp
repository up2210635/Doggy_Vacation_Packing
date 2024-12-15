// Fill out your copyright notice in the Description page of Project Settings.


#include "Time_Singleton.h"
#include <Kismet\GameplayStatics.h>

UTime_Singleton::UTime_Singleton()
{
	Time = 120;
}

void UTime_Singleton::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Warning, TEXT("Initialize of UTime_Singleton"));

	GetWorld()->GetTimerManager().SetTimer(FRoundTime, this, &UTime_Singleton::Counter, 1.0f, true, 0.0f);
}

void UTime_Singleton::Deinitialize()
{
	Super::Deinitialize();

	UE_LOG(LogTemp, Warning, TEXT("Deinitialize of UTime_Singleton"));
}

void UTime_Singleton::Add_Time(int Change)
{
	Time += Change;
}

int UTime_Singleton::Get_Time()
{
	return Time;
}

void UTime_Singleton::Counter()
{
	if (Time != 0)
	{
		Time--;
	}
	else
	{
		FName(FirstPersonMap) = *GetWorld()->GetName();
		UGameplayStatics::OpenLevel(GetWorld(), FirstPersonMap);
	}
}