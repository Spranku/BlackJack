// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BJGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BJ_API ABJGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SumUpEnemyCards(int Cout);

	UFUNCTION(BlueprintCallable)
	const int GetSumEnemyCards();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int SumEnemyCards = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnemyCanMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerCanMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerSkips = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ArrayOfEnemyCards;

	
};
