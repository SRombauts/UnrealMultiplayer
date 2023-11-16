// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#pragma once

#include "CoreMinimal.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MyReplicatedValue, Setter = SetMyReplicatedValue)
	int32 MyReplicatedValue = 42;

	UFUNCTION()
	virtual void OnRep_MyReplicatedValue(int32 OldReplicatedValue);
};
