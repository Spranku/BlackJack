// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

UENUM(BlueprintType)
enum class ECardSuit : uint8
{
	Hearts      UMETA(DisplayName = "Hearts"),
	Diamonds    UMETA(DisplayName = "Diamonds"),
	Clubs       UMETA(DisplayName = "Clubs"),
	Spades      UMETA(DisplayName = "Spades")
};

UENUM(BlueprintType)
enum class ECardRank : uint8
{
	Ace     UMETA(DisplayName = "Ace"),     // = 1
	Two     UMETA(DisplayName = "Two"),     // = 2
	Three   UMETA(DisplayName = "Three"),   // = 3
	Four    UMETA(DisplayName = "Four"),    // = 4
	Five    UMETA(DisplayName = "Five"),    // = 5
	Six     UMETA(DisplayName = "Six"),     // = 6
	Seven   UMETA(DisplayName = "Seven"),   // = 7
	Eight   UMETA(DisplayName = "Eight"),   // = 8
	Nine    UMETA(DisplayName = "Nine"),    // = 9
	Ten     UMETA(DisplayName = "Ten"),     // = 10
	Jack    UMETA(DisplayName = "Jack"),    // = 11
	Queen   UMETA(DisplayName = "Queen"),   // = 12
	King    UMETA(DisplayName = "King")     // = 13
};

UCLASS()
class BJ_API ACard : public AActor
{
	GENERATED_BODY()
public:
	// Компонент для отображения карты
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* CardMesh;

	// Динамический материал для изменения внешнего вида
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	// Инициализация визуала
	UFUNCTION(BlueprintCallable)
	void InitializeCardVisuals();

	// Обновление внешнего вида согласно масти/рангу
	UFUNCTION(BlueprintCallable)
	void UpdateAppearance();

	UFUNCTION(BlueprintCallable)
	int32 GetBlackjackValue(ECardRank Rank);

	UFUNCTION(BlueprintCallable, Category = "Card")
	FString GetCardInfo() const
	{
		return FString::Printf(TEXT("%s of %s"),
			*UEnum::GetDisplayValueAsText(Rank).ToString(),
			*UEnum::GetDisplayValueAsText(Suit).ToString());
	}
	
public:	
	// Sets default values for this actor's properties
	ACard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardSuit Suit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardRank Rank;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
