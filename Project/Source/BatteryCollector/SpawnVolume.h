// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; };

	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();
	
protected:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	void SpawnPickup();
	
};
