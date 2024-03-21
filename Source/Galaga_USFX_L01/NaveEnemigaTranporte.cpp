// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaTranporte.h"

ANaveEnemigaTranporte::ANaveEnemigaTranporte()
{

	velocidad = -300.0f;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/bf063f11968e_quiero_una_nave_tra.bf063f11968e_quiero_una_nave_tra'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));

}

void ANaveEnemigaTranporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaTranporte::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float DesplazamientoX = velocidad * DeltaTime;

	// Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);

	//si supera cierto limite en X vuelve a la posicion inicial
	if (NuevaPosicion.X < limiteInferiorX)
	{
		SetActorLocation(FVector(0.0f, PosicionActual.Y, PosicionActual.Z));
	}
}

void ANaveEnemigaTranporte::Destruirse()
{
}

void ANaveEnemigaTranporte::Escapar()
{
}
