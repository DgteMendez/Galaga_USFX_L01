// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "AlienigenaEnemigo.h"
#include "Proyectil.h"
#include "Escenario.h"
#include "NaveAmiga.h"
#include "Obstaculo.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTranporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaCazaG1.h"
#include "NaveEnemigaCazaG2.h"
#include "NaveEnemigaTranporteT1.h"
#include "NaveEnemigaTranporteT2.h"
#include "NaveEnemigaEspiaI1.h"
#include "NaveEnemigaEspiaT2.h"
#include "NaveEnemigaReabastecimientoE1.h"
#include "NaveEnemigaReabastecimientoH2.h"
#include "NaveEnemigaNodrizaC1.h"
#include "NaveEnemigaNodrizaC2.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();
	NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();

	//FVector ubicacionNave = FVector(-900.0f, 50.0f, 250.0f);
	//FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionAlienigena = FVector(1200.0f, 1300.0f, 250.0f);
	FRotator rotacionAlienigena = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionProyectil = FVector(1200.0f, 1400.0f, 250.0f);
	FRotator rotacionProyectil = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionEscenario = FVector(1200.0f, 1500.0f, 250.0f);
	FRotator rotacionEscenario = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionNaveAmiga = FVector(-1200.0f, 500.0f, 199.0f);
	FRotator rotacionNaveAmiga = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionObstaculo = FVector(1200.0f, 1600.0f, 250.0f);
	FRotator rotacionObstaculo = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionNaveEnemigaCaza = FVector(0.0f, -100.0f, 200.0f);
	FRotator rotacionNaveEnemigaCaza = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaTranporte = FVector(0.0f, 100.0f, 200.0f);
	FRotator rotacionNaveEnemigaTranporte = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaEspia = FVector(0.0f, 300.0f, 200.0f);
	FRotator rotacionNaveEnemigaEspia = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaReabastecimiento = FVector(0.0f, 500.0f, 200.0f);
	FRotator rotacionNaveEnemigaReabastecimiento = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaNodriza = FVector(800.0f, 200.0f, 200.0f);
	FRotator rotacionNaveEnemigaNodriza = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaCazaG1 = FVector(200.0f, -100.0f, 200.0f);
	FRotator rotacionNaveEnemigaCazaG1 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaCazaG2 = FVector(200.0f, 100.0f, 200.0f);
	FRotator rotacionNaveEnemigaCazaG2 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaEspiaI1 = FVector(200.0f, 300.0f, 200.0f);
	FRotator rotacionNaveEnemigaEspiaI1 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaEspiaT2 = FVector(200.0f, 500.0f, 200.0f);
	FRotator rotacionNaveEnemigaEspiaT2 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaTranporteT1 = FVector(400.0f, -100.0f, 200.0f);
	FRotator rotacionNaveEnemigaTranporteT1 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaTranporteT2 = FVector(400.0f, 100.0f, 200.0f);
	FRotator rotacionNaveEnemigaTranporteT2 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaReabastecimientoE1 = FVector(400.0f, 300.0f, 200.0f);
	FRotator rotacionNaveEnemigaReabastecimientoE1 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaReabastecimientoH2 = FVector(400.0f, 500.0f, 200.0f);
	FRotator rotacionNaveEnemigaReabastecimientoH2 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaNodrizaC1 = FVector(600.0f, 100.0f, 200.0f);
	FRotator rotacionNaveEnemigaNodrizaC1 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveEnemigaNodrizaC2 = FVector(600.0f, 300.0f, 200.0f);
	FRotator rotacionNaveEnemigaNodrizaC2 = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasCaza=FVector(200.0f, 200.0f, 200.0f);

	FVector ubicacionInicioNavesEnemigasTranporte=FVector(800.0f, 200.0f, 200.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{

		for (int i = 0; i < 5; i++) {


			ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicioNavesEnemigasCaza, rotacionNaveEnemigaCaza);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NaveEnemigaTemporal->SetVelocidad(-200);

		}

		for (int j = 0; j < 5; j++) {


			ubicacionInicioNavesEnemigasTranporte = ubicacionInicioNavesEnemigasTranporte + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaTranporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTranporte>(ubicacionInicioNavesEnemigasTranporte, rotacionNaveEnemigaCaza);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NaveEnemigaTemporal->SetVelocidad(-200);

		}
		
		
		//NaveEnemiga01 = World->SpawnActor<ANaveEnemiga>(ubicacionNave, rotacionNave);
		
		//AlienigenaEnemigo01 = World->SpawnActor<AAlienigenaEnemigo>(ubicacionAlienigena, rotacionAlienigena);
		//Proyectil01 = World->SpawnActor<AProyectil>(ubicacionProyectil, rotacionProyectil);
		//Escenario01 = World->SpawnActor<AEscenario>(ubicacionEscenario, rotacionEscenario);
		//NaveAmiga01 = World->SpawnActor<ANaveAmiga>(ubicacionNaveAmiga, rotacionNaveAmiga);
		//Obstaculo01 = World->SpawnActor<AObstaculo>(ubicacionObstaculo, rotacionObstaculo);

		//NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNaveEnemigaCaza, rotacionNaveEnemigaCaza);
		//NaveEnemigaCaza01->SetVelocidad(-400);

		//NaveEnemigaTranporte01 = World->SpawnActor<ANaveEnemigaTranporte>(ubicacionNaveEnemigaTranporte, rotacionNaveEnemigaTranporte);
		//NaveEnemigaTranporte01->SetVelocidad(-100);

		//NaveEnemigaEspia01 = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveEnemigaEspia, rotacionNaveEnemigaEspia);
		//NaveEnemigaEspia01->SetVelocidad(-300);

		//NaveEnemigaReabastecimiento01 = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionNaveEnemigaReabastecimiento, rotacionNaveEnemigaReabastecimiento);
		//NaveEnemigaReabastecimiento01->SetVelocidad(-200);

		//NaveEnemigaNodriza01 = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionNaveEnemigaNodriza, rotacionNaveEnemigaNodriza);
		//NaveEnemigaNodriza01->SetVelocidad(-50);

		//NaveEnemigaCazaG102 = World->SpawnActor<ANaveEnemigaCazaG1>(ubicacionNaveEnemigaCazaG1, rotacionNaveEnemigaCazaG1);
		//NaveEnemigaCazaG102->SetVelocidad(-200);
		//NaveEnemigaCazaG202 = World->SpawnActor<ANaveEnemigaCazaG2>(ubicacionNaveEnemigaCazaG2, rotacionNaveEnemigaCazaG2);
		//NaveEnemigaCazaG202->SetVelocidad(-200);
		//
		//NaveEnemigaEspiaI102 = World->SpawnActor<ANaveEnemigaEspiaI1>(ubicacionNaveEnemigaEspiaI1, rotacionNaveEnemigaEspiaI1);
		//NaveEnemigaEspiaI102->SetVelocidad(-150);
		//NaveEnemigaEspiaT202 = World->SpawnActor<ANaveEnemigaEspiaT2>(ubicacionNaveEnemigaEspiaT2, rotacionNaveEnemigaEspiaT2);
		//NaveEnemigaEspiaT202->SetVelocidad(-150);

		//NaveEnemigaTranporteT102 = World->SpawnActor<ANaveEnemigaTranporteT1>(ubicacionNaveEnemigaTranporteT1, rotacionNaveEnemigaTranporteT1);
		//NaveEnemigaTranporteT102->SetVelocidad(-50);
		//NaveEnemigaTranporteT202 = World->SpawnActor<ANaveEnemigaTranporteT2>(ubicacionNaveEnemigaTranporteT2, rotacionNaveEnemigaTranporteT2);
		//NaveEnemigaTranporteT202->SetVelocidad(-10);
		//
		//NaveEnemigaReabastecimientoE102 = World->SpawnActor<ANaveEnemigaReabastecimientoE1>(ubicacionNaveEnemigaReabastecimientoE1, rotacionNaveEnemigaReabastecimientoE1);
		//NaveEnemigaReabastecimientoE102->SetVelocidad(-100);
		//NaveEnemigaReabastecimientoH202 = World->SpawnActor<ANaveEnemigaReabastecimientoH2>(ubicacionNaveEnemigaReabastecimientoH2, rotacionNaveEnemigaReabastecimientoH2);
		//NaveEnemigaReabastecimientoH202->SetVelocidad(-100);
		//
		//NaveEnemigaNodrizaC102 = World->SpawnActor<ANaveEnemigaNodrizaC1>(ubicacionNaveEnemigaNodrizaC1, rotacionNaveEnemigaNodrizaC1);
		//NaveEnemigaNodrizaC102->SetVelocidad(-25);
		//NaveEnemigaNodrizaC202 = World->SpawnActor<ANaveEnemigaNodrizaC2>(ubicacionNaveEnemigaNodrizaC2, rotacionNaveEnemigaNodrizaC2);
		//NaveEnemigaNodrizaC202->SetVelocidad(-25);

	}

	//NaveEnemiga01->SetResistencia(100);
}

void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tiempoTranscurrido++;
	if (tiempoTranscurrido >= 50) {
		int numeroEnemigo = FMath::RandRange(1, 10);
	
		NavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;
		NavesEnemigas[numeroEnemigo]->SetVelocidad(0);
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El board está apareciendo")));
		}

		UE_LOG(LogTemp, Warning, TEXT("Hola"));
		tiempoTranscurrido = 0;
	}
}
