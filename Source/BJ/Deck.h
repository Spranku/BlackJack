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

	// Компонент для отображения колоды
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DeckMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* SphereComponent;

	// Инициализирует колоду из 52 карт
	UFUNCTION(BlueprintCallable)
	void InitializeDeck();

	// Перетасовывает колоду
	UFUNCTION(BlueprintCallable)
	void Shuffle();

	// Вытягивает карту сверху колоды
	UFUNCTION(BlueprintCallable)
	ACard* DrawCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<ACard*> Cards;

	// Шаблон карты для создания экземпляров
	UPROPERTY(EditDefaultsOnly, Category = "Deck")
	TSubclassOf<ACard> CardTemplate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
