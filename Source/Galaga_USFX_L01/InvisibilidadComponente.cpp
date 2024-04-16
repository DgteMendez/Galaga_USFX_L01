// Fill out your copyright notice in the Description page of Project Settings.


#include "InvisibilidadComponente.h"

// Sets default values for this component's properties
UInvisibilidadComponente::UInvisibilidadComponente()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UInvisibilidadComponente::AlternarVisibilidad()
{ 
    GetOwner()->SetActorHiddenInGame(visibilidad);
    if (visibilidad)
    {
        GetOwner()->SetActorHiddenInGame(true);
        visibilidad = false;
        GetWorld()->GetTimerManager().SetTimer(TempVisibilidad, this, &UInvisibilidadComponente::AlternarTempVisibilidad, DuracionInvisibilidad, false);
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Invisible"));
    }
    else
    {
        GetOwner()->SetActorHiddenInGame(false);
        visibilidad = true;
        GetWorld()->GetTimerManager().SetTimer(TempVisibilidad, this, &UInvisibilidadComponente::AlternarTempVisibilidad, DuracionVisibilidad, false);
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Visible"));
    }
}


void UInvisibilidadComponente::AlternarTempVisibilidad()
{
    AlternarVisibilidad();
}

// Called when the game starts
void UInvisibilidadComponente::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInvisibilidadComponente::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

