// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"


// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CardMesh"));
	CardMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CardMesh->SetRelativeScale3D(FVector(0.3f, 0.2f, 0.3f));
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACard::InitializeCardVisuals()
{
}

void ACard::UpdateAppearance()
{
   
}

int32 ACard::GetBlackjackValue(ECardRank CardRank)
{
    switch (CardRank)
    {
    case ECardRank::Ace:   return 11;
    case ECardRank::Two:   return 2;
    case ECardRank::Three: return 3;
    case ECardRank::Four:  return 4;
    case ECardRank::Five: return 5;
    case ECardRank::Six:  return 6;
    case ECardRank::Seven: return 7;
    case ECardRank::Eight: return 8;
    case ECardRank::Nine:  return 9;
    case ECardRank::Ten:
    case ECardRank::Jack:
    case ECardRank::Queen:
    case ECardRank::King: return 10;
    default: return static_cast<int32>(CardRank);
    }
}
