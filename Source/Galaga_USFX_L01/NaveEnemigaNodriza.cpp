// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

/*
*
*/

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	velocidad = 100.0f;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/7f63c0d3512a_QUIERO_UNA_NAVE_NOD.7f63c0d3512a_QUIERO_UNA_NAVE_NOD'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(3.0f, 3.0f, 3.0f));
}


void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float DesplazamientoX = velocidad * DeltaTime;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);

	if (NuevaPosicion.X > limiteSuperiorX)
	{
		SetActorLocation(FVector(0.0f, PosicionActual.Y, PosicionActual.Z));
	}
}

void ANaveEnemigaNodriza::Disparar()
{
}

void ANaveEnemigaNodriza::Destruirse()
{
}

void ANaveEnemigaNodriza::Esconderse()
{
}
