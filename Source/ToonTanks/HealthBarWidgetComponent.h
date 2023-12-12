// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HealthBarWidget.h"
#include "HealthBarWidgetComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TOONTANKS_API UHealthBarWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:	
	UHealthBarWidgetComponent();

	void SetHealth(float Health);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<UUserWidget> HealthBarWidget;
};
