// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoHorizontal.h"

// Sets default values for this component's properties
UMovimientoHorizontal::UMovimientoHorizontal()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Velocidad = -250.0f;
	LimiteIzquierda = -1800.0f;
	LimiteDerecha = 1800.0f;
	verificacion = true;

	// ...
}


// Called when the game starts
void UMovimientoHorizontal::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovimientoHorizontal::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();
	if (Parent)
	{
		if (verificacion) 
		{
			//auto NewPos = Parent->GetActorLocation() + FVector(0.0f, Velocidad * DeltaTime, 0.0f);
			auto NewPos = Parent->GetActorLocation() + FVector(Velocidad * DeltaTime, 0.0f, 0.0f);
			Parent->SetActorLocation(NewPos);
		}
		else 
		{
			auto NewPos = Parent->GetActorLocation() + FVector(-Velocidad * DeltaTime, 0.0f, 0.0f);
			//auto NewPos = Parent->GetActorLocation() + FVector(0.0f, -Velocidad * DeltaTime, 0.0f);
			Parent->SetActorLocation(NewPos);
		}
		
		if(Parent->GetActorLocation().X<LimiteIzquierda)
		{
			verificacion = false;
		}
		else if(Parent->GetActorLocation().X>LimiteDerecha)
		{
			verificacion = true;
		}
	}

	// ...
}

