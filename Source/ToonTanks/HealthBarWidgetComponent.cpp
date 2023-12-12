// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"

UHealthBarWidgetComponent::UHealthBarWidgetComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UHealthBarWidgetComponent::BeginPlay()
{
    Super::BeginPlay();

    if (HealthBarWidget)
    {
		SetWidget(CreateWidget(GetWorld(), HealthBarWidget, TEXT("Health Bar Widget")));
    }
}

void UHealthBarWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    FVector CLocation = GetComponentLocation();
    APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);

    if (CameraManager)
    {
        FVector CameraLocation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();
        FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(CLocation, CameraLocation);
        SetWorldRotation(PlayerRot);
    }
}

void UHealthBarWidgetComponent::SetHealth(float Health)
{
    UHealthBarWidget* CurrentWidget = Cast<UHealthBarWidget>(GetWidget());

    if (CurrentWidget)
    {
        UProgressBar* ProgressBar = Cast<UProgressBar>(CurrentWidget->GetWidgetFromName(FName("HealthBar")));
        FString ObjectName = GetOwner()->GetName();

        if (ProgressBar)
        {
            ProgressBar->SetPercent(Health);
        }
        
    }
}
