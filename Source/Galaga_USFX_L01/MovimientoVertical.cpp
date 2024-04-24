// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoVertical.h"

// Sets default values for this component's properties
UMovimientoVertical::UMovimientoVertical()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Rapidez = 250.0f;
	LimiteAbajo = -1500.0f;
	LimiteArriba = 600.0f;
	verificacion = true;
	// ...
}


// Called when the game starts
void UMovimientoVertical::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovimientoVertical::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();
	if (Parent)
	{
		if (verificacion)
		{
			auto NewPos = Parent->GetActorLocation() + FVector(Rapidez * DeltaTime, 0.0f, 0.0f);
			//auto NewPos = Parent->GetActorLocation() + FVector(Velocidad * DeltaTime, 0.0f, 0.0f);
			Parent->SetActorLocation(NewPos);
		}
		else
		{
			auto NewPos = Parent->GetActorLocation() + FVector(-Rapidez * DeltaTime, 0.0f, 0.0f);
			//auto NewPos = Parent->GetActorLocation() + FVector(-Velocidad * DeltaTime, 0.0f, 0.0f);
			Parent->SetActorLocation(NewPos);
		}

		if (Parent->GetActorLocation().X > LimiteArriba)
		{
			verificacion = false;
		}
		else if (Parent->GetActorLocation().X < LimiteAbajo)
		{
			verificacion = true;
		}
	}

	// ...
}

