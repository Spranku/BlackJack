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
	UFUNCTION(BlueprintImplementableEvent)
	void Action1_BP();

	UFUNCTION(BlueprintImplementableEvent)
	void Action2_BP();
	
};
