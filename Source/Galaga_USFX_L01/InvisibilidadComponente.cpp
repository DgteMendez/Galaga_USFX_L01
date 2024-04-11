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
    visibilidad = !visibilidad; 
    GetOwner()->SetActorHiddenInGame(visibilidad);
    if (visibilidad)
    {
        GetOwner()->SetActorHiddenInGame(true);
        visibilidad = false;
        GetWorld()->GetTimerManager().SetTimer(TempVisibilidad, this, &UInvisibilidadComponente::AlternarTempVisibilidad, DuracionInvisibilidad, false);
    }
    else
    {
        GetOwner()->SetActorHiddenInGame(false);
        visibilidad = true;
        GetWorld()->GetTimerManager().SetTimer(TempVisibilidad, this, &UInvisibilidadComponente::AlternarTempVisibilidad, DuracionVisibilidad, false);
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

