// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Bomba.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	velocidad = -500.0f;
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/ASETS/d81ab483e5cf_quiero_que_me_hagas.d81ab483e5cf_quiero_que_me_hagas'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//MovimientoHorizontal = CreateDefaultSubobject<UMovimientoHorizontal>(TEXT("MovimientoAleatorio"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Mover(DeltaTime);

	TiempoTranscurrido++;
	if (TiempoTranscurrido > 500)
	{
		int NumAleatorio = FMath::RandRange(0, 3);
		int probabilidad = 1;
		if (NumAleatorio < probabilidad)
		{
			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				FVector ubicacionBomba = GetActorLocation() + FVector(0.0f, 100.0f, 0.0f);
				World->SpawnActor<ABomba>(ubicacionBomba, FRotator::ZeroRotator);
			}
		}
		TiempoTranscurrido = 0;
	}
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	/*FVector PosicionActual = GetActorLocation();

	float DesplazamientoX = velocidad * DeltaTime;

	FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX, PosicionActual.Y, PosicionActual.Z);

	SetActorLocation(NuevaPosicion);

	if (NuevaPosicion.X < limiteInferiorX)
	{
		SetActorLocation(FVector(-500.0f, PosicionActual.Y, PosicionActual.Z));
	}*/
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
