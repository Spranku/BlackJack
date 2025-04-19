// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.h"
#include "Deck.generated.h"

class USphereComponent;

UCLASS()
class BJ_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

	// Mesh for visual cards
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DeckMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* SphereComponent;

	// Init 52 cards
	UFUNCTION(BlueprintCallable)
	void InitializeDeck();

	// Reload cards
	UFUNCTION(BlueprintCallable)
	void Shuffle();

	// Get card from top
	UFUNCTION(BlueprintCallable)
	ACard* DrawCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<ACard*> Cards;

	UPROPERTY(EditDefaultsOnly, Category = "Deck")
	TSubclassOf<ACard> CardTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayerOffset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EnemyOffset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsFirst = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
