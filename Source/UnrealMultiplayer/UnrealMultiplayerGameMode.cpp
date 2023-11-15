// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#include "UnrealMultiplayerGameMode.h"

#include "UnrealMultiplayer.h"
#include "UnrealMultiplayerCharacter.h"

#include "UObject/ConstructorHelpers.h"


AUnrealMultiplayerGameMode::AUnrealMultiplayerGameMode()
{
}

void AUnrealMultiplayerGameMode::HostGame(FString MapURL)
{
	// TODO: can only really be called on the server, right!?
	if (UWorld* World = GetWorld())
	{
		UE_LOG(LogMultiplayer, Log, TEXT("[%s] HostGame(InMapURL=%s)"), *GetName(), *MapURL)
		World->ServerTravel(MapURL);
	}
}

void AUnrealMultiplayerGameMode::JoinGame(FString IPAddress)
{
	if (APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController())
	{
		UE_LOG(LogMultiplayer, Log, TEXT("[%s] JoinGame(InMapURL=%s)"), *GetName(), *IPAddress)
		PC->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);
	}
}
