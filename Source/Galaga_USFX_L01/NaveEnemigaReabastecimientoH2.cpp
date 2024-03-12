// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimientoH2.h"

ANaveEnemigaReabastecimientoH2::ANaveEnemigaReabastecimientoH2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
}

void ANaveEnemigaReabastecimientoH2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaReabastecimientoH2::Mover(float DeltaTime)
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

void ANaveEnemigaReabastecimientoH2::Destruirse()
{
}
