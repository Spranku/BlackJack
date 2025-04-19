// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    DeckMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DeckMesh"));
    DeckMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    //DeckMesh->SetRelativeScale3D(FVector(0.3f, 0.2f, 0.3f));

    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SphereComponent->SetSphereRadius(15.0f);
}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeck::InitializeDeck()
{
    if (!CardTemplate) return;

    Cards.Empty();

    // Create all Suits and Ranks
    for (uint8 s = 0; s < static_cast<uint8>(ECardSuit::Spades) + 1; s++)
    {
        for (uint8 r = 0; r < static_cast<uint8>(ECardRank::King) + 1; r++)
        {
            ACard* NewCard = GetWorld()->SpawnActor<ACard>(CardTemplate, SphereComponent->GetComponentLocation()/*FVector::ZeroVector*/, FRotator::ZeroRotator);
            NewCard->Suit = static_cast<ECardSuit>(s);
            NewCard->Rank = static_cast<ECardRank>(r);
            Cards.Add(NewCard);
        }
    }

    Shuffle();
}

void ADeck::Shuffle()
{
    for (int32 i = Cards.Num() - 1; i > 0; i--)
    {
        int32 j = FMath::RandRange(0, i);
        Cards.Swap(i, j);
    }
}

ACard* ADeck::DrawCard()
{
    if (Cards.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Deck is empty!"));
        return nullptr;
    }

    ACard* TopCard = Cards.Pop();
    return TopCard;
}
