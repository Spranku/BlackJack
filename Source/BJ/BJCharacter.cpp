// Fill out your copyright notice in the Description page of Project Settings.


#include "BJCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BJGameModeBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABJCharacter::ABJCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent()); 
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->SetFieldOfView(110.0f);
}

// Called when the game starts or when spawned
void ABJCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABJCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABJCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Action1", IE_Pressed, this, &ABJCharacter::EnableActionOne);
	PlayerInputComponent->BindAction("Action1", IE_Released, this, &ABJCharacter::DisableActionOne);

	PlayerInputComponent->BindAction("Action2", IE_Pressed, this, &ABJCharacter::EnableActionTwo);
	PlayerInputComponent->BindAction("Action2", IE_Released, this, &ABJCharacter::DisableActionTwo);
}

void ABJCharacter::EnableActionOne()
{

}

void ABJCharacter::DisableActionOne()
{
}

void ABJCharacter::EnableActionTwo()
{

}

void ABJCharacter::DisableActionTwo()
{
}

