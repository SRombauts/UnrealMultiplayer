// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealMultiplayerGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealMultiplayerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealMultiplayerGameMode();

	// Travel to the map and start listening for client connections. Call with MapURL "/Game/ThirdPerson/Maps/ThirdPersonExampleMap?listen"
	// NOTE: can only be called on a standalone game (or a listen server), as the game mode is server-side only 
	UFUNCTION(BlueprintCallable)
	void HostGame(FString MapURL);

	// Connect to the server listening at the IP address
	// NOTE: can only be called on a standalone game (or a listen server), as the game mode is server-side only
	UFUNCTION(BlueprintCallable)
	void JoinGame(FString IPAddress);
};



