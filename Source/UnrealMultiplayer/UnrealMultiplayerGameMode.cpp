// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#include "UnrealMultiplayerGameMode.h"
#include "UnrealMultiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealMultiplayerGameMode::AUnrealMultiplayerGameMode()
{
}

void AUnrealMultiplayerGameMode::HostGame(FString InMapURL)
{
	if (UWorld* World = GetWorld())
	{
		World->ServerTravel(InMapURL);
	}
}

void AUnrealMultiplayerGameMode::JoinGame(FString IPAddress)
{
	if (APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController())
	{
		PC->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);
	}
}
