// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#include "MyBox.h"

#include "UnrealMultiplayer.h"

#include "Net/UnrealNetwork.h"

AMyBox::AMyBox()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}

void AMyBox::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyBox, MyReplicatedValue);
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

void AMyBox::SetMyReplicatedValue(int32 InReplicatedValue)
{
	if (HasAuthority())
	{
		const int32 OldReplicatedValue = MyReplicatedValue;
		MyReplicatedValue = InReplicatedValue;

		OnRep_MyReplicatedValue(OldReplicatedValue);
	}
}

void AMyBox::OnRep_MyReplicatedValue(int32 OldReplicatedValue)
{
	UE_LOG(LogMultiplayer, Log, TEXT("[%s] OnRep_MyReplicatedValue: %d->%d"), *GetName(), OldReplicatedValue, MyReplicatedValue);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("OnRep_MyReplicatedValue: %d->%d"), OldReplicatedValue, MyReplicatedValue));
}
