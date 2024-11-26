// Copyright Epic Games, Inc. All Rights Reserved.

#include "Doggy_VacationGameMode.h"
#include "UObject/ConstructorHelpers.h"


ADoggy_VacationGameMode::ADoggy_VacationGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Dog"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
