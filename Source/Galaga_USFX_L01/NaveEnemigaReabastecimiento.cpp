// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"

/*
*
*/

ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	velocidad = -200.0f;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/b60f1aa1845d_QUIERO_UNA_NAVE_INT.b60f1aa1845d_QUIERO_UNA_NAVE_INT'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
}

void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
{
	/*// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float DesplazamientoY = velocidad * DeltaTime;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X, PosicionActual.Y + DesplazamientoY, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);

	if (NuevaPosicion.Y < limiteIzquierdaY)
	{
		SetActorLocation(FVector(PosicionActual.X, -300.0f, PosicionActual.Z));
	}*/
}

void ANaveEnemigaReabastecimiento::Destruirse()
{
}
