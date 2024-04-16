// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	velocidad = 200.0f;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/3e2b0fdd41c6_creamelo_una_nave_d.3e2b0fdd41c6_creamelo_una_nave_d'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}


void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	// Obtiene la posición actual del actor
	/*FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float DesplazamientoY = velocidad * DeltaTime;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X, PosicionActual.Y + DesplazamientoY, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);

	if (NuevaPosicion.Y > limiteDerechaY)
	{
		SetActorLocation(FVector(PosicionActual.X, 300.0f, PosicionActual.Z));
	}*/
}

void ANaveEnemigaEspia::Disparar()
{
}

void ANaveEnemigaEspia::Destruirse()
{
}

void ANaveEnemigaEspia::Atacar()
{
}

void ANaveEnemigaEspia::Esconderse()
{
}

void ANaveEnemigaEspia::Escapar()
{
}
