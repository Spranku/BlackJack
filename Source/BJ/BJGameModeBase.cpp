// Copyright Epic Games, Inc. All Rights Reserved.


#include "BJGameModeBase.h"

void ABJGameModeBase::SumUpEnemyCards(int Cout)
{
	SumEnemyCards += Cout;
	ArrayOfEnemyCards.Add(Cout);
}

const int ABJGameModeBase::GetSumEnemyCards()
{
	return SumEnemyCards;
}
