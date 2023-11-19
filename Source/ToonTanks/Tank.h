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

	public:
		ATank();

	
	protected:
		/** Called for movement input */
		void Move(const FInputActionValue& Value);

		/** Called for movement input */
		void Rotate(const FInputActionValue& Value);

		/** Called for movement input */
		void Fire(const FInputActionValue& Value);

	protected:
		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		// To add mapping context
		virtual void BeginPlay();		
};
