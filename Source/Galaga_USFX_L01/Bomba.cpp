// Fill out your copyright notice in the Description page of Project Settings.

#//include "MovimientoHorizontal.h"
#include "Bomba.h"

ABomba::ABomba()
{
	velocidad = -500.0f;
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/8677a9580f86_una_bomba_de_tiempo.8677a9580f86_una_bomba_de_tiempo'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//MovimientoHorizontal = CreateDefaultSubobject<UMovimientoHorizontal>(TEXT("MovimientoAleatorio"));
	ProyectilMesh->SetStaticMesh(ShipMesh.Object);
}

void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ABomba::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();
	float DesplazamientoX = velocidad * DeltaTime;
	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);
	SetActorLocation(NuevaPosicion);
}