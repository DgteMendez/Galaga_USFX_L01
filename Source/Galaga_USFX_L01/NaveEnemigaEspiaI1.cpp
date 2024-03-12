// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaI1.h"

ANaveEnemigaEspiaI1::ANaveEnemigaEspiaI1()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_In.Shape_Trim_90_In'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
}

void ANaveEnemigaEspiaI1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaEspiaI1::Mover(float DeltaTime)
{
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float DesplazamientoX = GetVelocidad() * DeltaTime;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaEspiaI1::Disparar()
{
}

void ANaveEnemigaEspiaI1::Destruirse()
{
}

void ANaveEnemigaEspiaI1::Atacar()
{
}

void ANaveEnemigaEspiaI1::Esconderse()
{
}
