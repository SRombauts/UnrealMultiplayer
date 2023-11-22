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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Server: BeginPlay: Has Authority"));

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyBox::OnTimer, 1.f, true, 3);
	}
	else
	{
		UE_LOG(LogMultiplayer, Log, TEXT("[%s] BeginPlay: No Authority"), *GetName());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Client: BeginPlay: No Authority"));
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
	if (HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Server: OnRep_MyReplicatedValue: %d->%d"), OldReplicatedValue, MyReplicatedValue));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Client %d: OnRep_MyReplicatedValue: %d->%d"), GPlayInEditorID, OldReplicatedValue, MyReplicatedValue));
	}
}

void AMyBox::OnTimer()
{
	UE_LOG(LogMultiplayer, Log, TEXT("[%s] OnTimer"), *GetName());
	SetMyReplicatedValue(MyReplicatedValue - 1);
	
	if (MyReplicatedValue <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
}
