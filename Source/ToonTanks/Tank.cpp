// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"



ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

void ATank::BeginPlay()
{	
	// Call the base class  
	Super::BeginPlay();
	//Add Input Mapping Context
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{	

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{	
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {		
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATank::Move);

		// Rotating
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ATank::Rotate);

        // Firing
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &ATank::Fire);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}

}


void ATank::Move(const FInputActionValue& Value)
{	
    if (Controller != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("TANK: Move with CTRL"));
    }

}

void ATank::Rotate(const FInputActionValue& Value)
{
    if (Controller != nullptr)
	{
        
    }
}

void ATank::Fire(const FInputActionValue& Value)
{
    if (Controller != nullptr)
	{
        
    }
}
