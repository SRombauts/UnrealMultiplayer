// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#include "MyBox.h"

#include "UnrealMultiplayer.h"

AMyBox::AMyBox()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyBox::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		UE_LOG(LogMultiplayer, Log, TEXT("[%s] BeginPlay: Has Authority"), *GetName());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BeginPlay: Has Authority"));
	}
	else
	{
		UE_LOG(LogMultiplayer, Log, TEXT("[%s] BeginPlay: No Authority"), *GetName());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("BeginPlay: No Authority"));
	}
}
