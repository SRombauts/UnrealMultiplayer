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

	// Travel to the map and start listening for client connections
	UFUNCTION(BlueprintCallable)
	void HostGame(FString InMapURL);

	// Connect to the server listening at the IP address
	UFUNCTION(BlueprintCallable)
	void JoinGame(FString IPAddress);
};



