// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	velocidad = -500.0f;
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/d81ab483e5cf_quiero_que_me_hagas.d81ab483e5cf_quiero_que_me_hagas'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
}


void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float DesplazamientoX = velocidad * DeltaTime;

	// Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);

	if (NuevaPosicion.X < limiteInferiorX)
	{
		SetActorLocation(FVector(0.0f, PosicionActual.Y, PosicionActual.Z));
	}
}

void ANaveEnemigaCaza::Disparar()
{
}

void ANaveEnemigaCaza::Destruirse()
{
}

void ANaveEnemigaCaza::Atacar()
{
}
