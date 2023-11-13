// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMultiplayerGameMode.h"
#include "UnrealMultiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealMultiplayerGameMode::AUnrealMultiplayerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
