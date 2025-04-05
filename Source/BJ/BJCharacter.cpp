// Fill out your copyright notice in the Description page of Project Settings.


#include "BJCharacter.h"
#include "Camera/CameraComponent.h"
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
}

