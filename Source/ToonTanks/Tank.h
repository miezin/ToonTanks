// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

	private:
		UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* SpringArm;
			
		UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* Camera;

		/** MappingContext */
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* DefaultMappingContext;

		/** Move Input Action */
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* MoveAction;

		/** Look Input Action */
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* RotateAction;

		/** Look Input Action */
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* FireAction;

		APlayerController* PlayerControllerRef;

	public:
		ATank();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

	
	protected:
		UPROPERTY(EditAnywhere, Category = "Movement")
		float Speed = 200.f;

		UPROPERTY(EditAnywhere, Category = "Movement")
		float TurnRate = 45.f;


		/** Called for movement input */
		void Move(const FInputActionValue& Value);

		/** Called for movement input */
		void Fire(const FInputActionValue& Value);

	protected:
		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		// To add mapping context
		virtual void BeginPlay();		
};
