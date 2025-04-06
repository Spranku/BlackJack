// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BJCharacter.generated.h"

class ABJGameModeBase;
class UCameraComponent;

UCLASS()
class BJ_API ABJCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABJCharacter();

	UCameraComponent* FirstPersonCameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void EnableActionOne();

	void DisableActionOne();

	void EnableActionTwo();

	void DisableActionTwo();

	ABJGameModeBase* GameMode = nullptr;
};
