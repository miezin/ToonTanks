// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:	
	UHealthBarWidget(const FObjectInitializer& ObjectInitializer);

	void SetHealth(float NewHealth) { Health = NewHealth;}
	void SetHealthText(FString NewHealthText) { HealthText = NewHealthText;}

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	float Health = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	FString HealthText = "12345";
};
