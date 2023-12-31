// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/Actor.h"
#include "MyBox.generated.h"

UCLASS()
class UNREALMULTIPLAYER_API AMyBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBox();

	/** Returns the properties used for network replication, this needs to be overridden by all actor classes with native replicated properties */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
	void SetMyReplicatedValue(int32 InReplicatedValue);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void MulticastExplode();

public:
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MyReplicatedValue, Setter = SetMyReplicatedValue)
	int32 MyReplicatedValue = 3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	virtual void OnRep_MyReplicatedValue(int32 InOldReplicatedValue);
	
	void OnTimer();

private:
	FTimerHandle TimerHandle;
};
