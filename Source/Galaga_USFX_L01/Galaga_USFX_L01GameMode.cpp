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
#include "InventoryActor.h"
#include "InventoryGun.h"
#include "InvisibilidadComponente.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();
	NaveEnemiga01 = nullptr;

	for (AActor* NaveEnemiga : NavesEnemigas)
	{
		UInvisibilidadComponente* InvisibilidadComponente = NewObject<UInvisibilidadComponente>(NaveEnemiga, TEXT("InvisibleComponent"));
		InvisibilidadComponente->RegisterComponent();
		NaveEnemiga->AddOwnedComponent(InvisibilidadComponente);
	}
	
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();

	/*FVector ubicacionNave = FVector(-900.0f, 50.0f, 250.0f);
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionAlienigena = FVector(1200.0f, 1300.0f, 250.0f);
	FRotator rotacionAlienigena = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionProyectil = FVector(1200.0f, 1400.0f, 250.0f);
	FRotator rotacionProyectil = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionEscenario = FVector(1200.0f, 1500.0f, 250.0f);
	FRotator rotacionEscenario = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionNaveAmiga = FVector(-1200.0f, 500.0f, 199.0f);
	FRotator rotacionNaveAmiga = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionObstaculo = FVector(800.0f, -1600.0f, 250.0f);
	FRotator rotacionObstaculo = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector ubicacionNaveEnemigaCaza = FVector(600.0f, 0.0f, 200.0f);
	FRotator rotacionNaveEnemigaCaza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionNaveEnemigaTranporte = FVector(400.0f, 0.0f, 200.0f);
	FRotator rotacionNaveEnemigaTranporte = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionNaveEnemigaEspia = FVector(0.0f, 300.0f, 200.0f);
	FRotator rotacionNaveEnemigaEspia = FRotator(0.0f, 180.0f, 0.0f);

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
	FRotator rotacionNaveEnemigaNodrizaC2 = FRotator(0.0f, 0.0f, 0.0f);*/

	FVector ubicacionInicioNavesEnemigasCaza=FVector(600.0f, -600.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasCaza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasTranporte=FVector(400.0f, -600.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasTranporte = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(0.0f, 300.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasEspia = FRotator(0.0f, 270.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasReabastecimiento = FVector(0.0f, -300.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasReabastecimiento = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasNodriza = FVector(800.0f, -1400.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasNodriza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInventoryActor = FVector(-1800.0f, -1800.0f, 250.0f);
	FRotator rotacionInventoryActor = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionInventoryGun = FVector(-1800.0f, 1800.0f, 250.0f);
	FRotator rotacionInventoryGun = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{

		for (int i = 0; i < 6; i++) {

			ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicioNavesEnemigasCaza, rotacionInicioNavesEnemigasCaza);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);

		}

		for (int j = 0; j < 6; j++) {

			ubicacionInicioNavesEnemigasTranporte = ubicacionInicioNavesEnemigasTranporte + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaTranporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTranporte>(ubicacionInicioNavesEnemigasTranporte, rotacionInicioNavesEnemigasTranporte);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);

		}

		for (int k = 0; k < 6; k++) {

			ubicacionInicioNavesEnemigasEspia = ubicacionInicioNavesEnemigasEspia + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaEspia* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaEspia>(ubicacionInicioNavesEnemigasEspia, rotacionInicioNavesEnemigasEspia);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);

		}

		for (int l = 0; l < 6; l++) {

			ubicacionInicioNavesEnemigasReabastecimiento = ubicacionInicioNavesEnemigasReabastecimiento + FVector(0.0f, -200.0f, 0.0f);
			ANaveEnemigaReabastecimiento* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionInicioNavesEnemigasReabastecimiento, rotacionInicioNavesEnemigasReabastecimiento);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);

		}

		for (int m = 0; m < 6; m++) {

			ubicacionInicioNavesEnemigasNodriza = ubicacionInicioNavesEnemigasNodriza + FVector(0.0f, 400.0f, 0.0f);
			ANaveEnemigaNodriza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionInicioNavesEnemigasNodriza, rotacionInicioNavesEnemigasNodriza);
			NavesEnemigas.Push(NaveEnemigaTemporal);
			NavesEnemigas.Push(NaveEnemigaTemporal);

		}

		/*NavesEnemigas[1]->SetActorHiddenInGame(true);
		NavesEnemigas[1]->visibilidad = false;
		NavesEnemigas[2]->SetActorHiddenInGame(true);
		NavesEnemigas[2]->visibilidad = false;
		NavesEnemigas[4]->SetActorHiddenInGame(true);
		NavesEnemigas[4]->visibilidad = false;
		NavesEnemigas[6]->SetActorHiddenInGame(true);
		NavesEnemigas[6]->visibilidad = false;
		NavesEnemigas[8]->SetActorHiddenInGame(true);
		NavesEnemigas[8]->visibilidad = false;
		NavesEnemigas[10]->SetActorHiddenInGame(true);
		NavesEnemigas[10]->visibilidad = false;
		NavesEnemigas[12]->SetActorHiddenInGame(true);
		NavesEnemigas[12]->visibilidad = false;
		NavesEnemigas[14]->SetActorHiddenInGame(true);
		NavesEnemigas[14]->visibilidad = false;
		NavesEnemigas[16]->SetActorHiddenInGame(true);
		NavesEnemigas[16]->visibilidad = false;
		NavesEnemigas[18]->SetActorHiddenInGame(true);
		NavesEnemigas[18]->visibilidad = false;
		NavesEnemigas[20]->SetActorHiddenInGame(true);
		NavesEnemigas[20]->visibilidad = false;
		NavesEnemigas[22]->SetActorHiddenInGame(true);
		NavesEnemigas[22]->visibilidad = false;*/

		//TMap

		/*for (int i = 0; i < 1; i++) {

			FVector SpawnLocation = FVector((-600.0f), FMath::RandRange(-1000.0f, 1000.0f), 200.0f);
			AObstaculo* NewObstaculo = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMObstaculosYAlienigenas.Add(SpawnLocation, NewObstaculo);

		}*/

		InventoryActor01 = World->SpawnActor<AInventoryActor>(ubicacionInventoryActor, rotacionInventoryActor);

		InventoryGun01 = World->SpawnActor<AInventoryGun>(ubicacionInventoryGun, rotacionInventoryGun);

		/*NaveEnemiga01 = World->SpawnActor<ANaveEnemiga>(ubicacionNave, rotacionNave);

		AlienigenaEnemigo01 = World->SpawnActor<AAlienigenaEnemigo>(ubicacionAlienigena, rotacionAlienigena);
		Proyectil01 = World->SpawnActor<AProyectil>(ubicacionProyectil, rotacionProyectil);
		Escenario01 = World->SpawnActor<AEscenario>(ubicacionEscenario, rotacionEscenario);
		NaveAmiga01 = World->SpawnActor<ANaveAmiga>(ubicacionNaveAmiga, rotacionNaveAmiga);
		
		Obstaculo01 = World->SpawnActor<AObstaculo>(ubicacionObstaculo, rotacionObstaculo);

		NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNaveEnemigaCaza, rotacionNaveEnemigaCaza);
		NaveEnemigaCaza01->SetVelocidad(-400);

		NaveEnemigaTranporte01 = World->SpawnActor<ANaveEnemigaTranporte>(ubicacionNaveEnemigaTranporte, rotacionNaveEnemigaTranporte);
		NaveEnemigaTranporte01->SetVelocidad(-100);

		NaveEnemigaEspia01 = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveEnemigaEspia, rotacionNaveEnemigaEspia);
		NaveEnemigaEspia01->SetVelocidad(-300);

		NaveEnemigaReabastecimiento01 = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionNaveEnemigaReabastecimiento, rotacionNaveEnemigaReabastecimiento);
		NaveEnemigaReabastecimiento01->SetVelocidad(-200);

		NaveEnemigaNodriza01 = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionNaveEnemigaNodriza, rotacionNaveEnemigaNodriza);
		NaveEnemigaNodriza01->SetVelocidad(-50);

		NaveEnemigaCazaG102 = World->SpawnActor<ANaveEnemigaCazaG1>(ubicacionNaveEnemigaCazaG1, rotacionNaveEnemigaCazaG1);
		NaveEnemigaCazaG102->SetVelocidad(-200);
		NaveEnemigaCazaG202 = World->SpawnActor<ANaveEnemigaCazaG2>(ubicacionNaveEnemigaCazaG2, rotacionNaveEnemigaCazaG2);
		NaveEnemigaCazaG202->SetVelocidad(-200);
		
		NaveEnemigaEspiaI102 = World->SpawnActor<ANaveEnemigaEspiaI1>(ubicacionNaveEnemigaEspiaI1, rotacionNaveEnemigaEspiaI1);
		NaveEnemigaEspiaI102->SetVelocidad(-150);
		NaveEnemigaEspiaT202 = World->SpawnActor<ANaveEnemigaEspiaT2>(ubicacionNaveEnemigaEspiaT2, rotacionNaveEnemigaEspiaT2);
		NaveEnemigaEspiaT202->SetVelocidad(-150);

		NaveEnemigaTranporteT102 = World->SpawnActor<ANaveEnemigaTranporteT1>(ubicacionNaveEnemigaTranporteT1, rotacionNaveEnemigaTranporteT1);
		NaveEnemigaTranporteT102->SetVelocidad(-50);
		NaveEnemigaTranporteT202 = World->SpawnActor<ANaveEnemigaTranporteT2>(ubicacionNaveEnemigaTranporteT2, rotacionNaveEnemigaTranporteT2);
		NaveEnemigaTranporteT202->SetVelocidad(-10);
		
		NaveEnemigaReabastecimientoE102 = World->SpawnActor<ANaveEnemigaReabastecimientoE1>(ubicacionNaveEnemigaReabastecimientoE1, rotacionNaveEnemigaReabastecimientoE1);
		NaveEnemigaReabastecimientoE102->SetVelocidad(-100);
		NaveEnemigaReabastecimientoH202 = World->SpawnActor<ANaveEnemigaReabastecimientoH2>(ubicacionNaveEnemigaReabastecimientoH2, rotacionNaveEnemigaReabastecimientoH2);
		NaveEnemigaReabastecimientoH202->SetVelocidad(-100);
		
		NaveEnemigaNodrizaC102 = World->SpawnActor<ANaveEnemigaNodrizaC1>(ubicacionNaveEnemigaNodrizaC1, rotacionNaveEnemigaNodrizaC1);
		NaveEnemigaNodrizaC102->SetVelocidad(-25);
		NaveEnemigaNodrizaC202 = World->SpawnActor<ANaveEnemigaNodrizaC2>(ubicacionNaveEnemigaNodrizaC2, rotacionNaveEnemigaNodrizaC2);
		NaveEnemigaNodrizaC202->SetVelocidad(-25);*/

	}

	//NaveEnemiga01->SetResistencia(100);
}

/*void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tiempoTranscurrido++;
	if (tiempoTranscurrido >= 50) {
		int numeroEnemigo = FMath::RandRange(1, 5);
		NavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;

		NavesEnemigas[numeroEnemigo]->SetActorHiddenInGame(true);


		if (GEngine) {
		}
		tiempoTranscurrido = 0;
	}
}*/

/*void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	tiempoTranscurrido++;

	if (tiempoTranscurrido >= 200)
	{
		for (int i = 0; i < 5; i++) {

			int numeroEnemigo = FMath::RandRange(1, 20);

			if (NavesEnemigas[numeroEnemigo]->visibilidad)
			{
				tiempoInvisible++;

				if (tiempoInvisible >= 0)
				{
					NavesEnemigas[numeroEnemigo]->SetActorHiddenInGame(true);
					NavesEnemigas[numeroEnemigo]->visibilidad = false;
					tiempoVisible = 0;
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("invisible"));
				}
			}
			else
			{
				tiempoVisible++;

				if (tiempoVisible >= 0)
				{
					NavesEnemigas[numeroEnemigo]->SetActorHiddenInGame(false);
					NavesEnemigas[numeroEnemigo]->visibilidad = true;
					tiempoInvisible = 0;
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("visible"));
				}
			}

			tiempoTranscurrido = 0;

		}

	}
}*/

/*void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	tiempoTranscurrido++;

	if (tiempoTranscurrido >= 50)
	{
		// Lista para almacenar las naves que cambiarán de visibilidad
		TArray<int> navesACambiar;

		// Elegir aleatoriamente 5 naves para cambiar su visibilidad
		while (navesACambiar.Num() < 5)
		{
			int numeroEnemigo = FMath::RandRange(1, 20);

			// Verificar si la nave ya ha sido seleccionada
			if (!navesACambiar.Contains(numeroEnemigo))
			{
				navesACambiar.Add(numeroEnemigo);
			}
		}

		// Cambiar la visibilidad de las 5 naves seleccionadas
		for (int i = 0; i < navesACambiar.Num(); i++)
		{
			int numeroEnemigo = navesACambiar[i];

			if (NavesEnemigas[numeroEnemigo]->visibilidad)
			{
				tiempoInvisible++;

				if (tiempoInvisible >= 10)
				{
					NavesEnemigas[numeroEnemigo]->SetActorHiddenInGame(true);
					NavesEnemigas[numeroEnemigo]->visibilidad = false;
					tiempoInvisible = 0;
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Nave %d invisible"), numeroEnemigo));
				}
			}
			else
			{
				tiempoVisible++;

				if (tiempoVisible >= 10)
				{
					NavesEnemigas[numeroEnemigo]->SetActorHiddenInGame(false);
					NavesEnemigas[numeroEnemigo]->visibilidad = true;
					tiempoVisible = 0;
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Nave %d visible"), numeroEnemigo));
				}
			}
		}

		tiempoTranscurrido = 0;
	}
}*/

void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	tiempoTranscurrido++;

	if (tiempoTranscurrido >= 500)
	{
		// Lista para almacenar las naves que cambiarán de visibilidad
		TArray<int> navesACambiar;

		// Elegir aleatoriamente 5 naves para cambiar su visibilidad
		while (navesACambiar.Num() < 5)
		{
			int numeroEnemigo = FMath::RandRange(0, 20);

			// Verificar si la nave ya ha sido seleccionada
			if (!navesACambiar.Contains(numeroEnemigo))
			{
				navesACambiar.Add(numeroEnemigo);
			}
		}

		// Hacer invisibles las 5 naves seleccionadas
		for (int i = 0; i < navesACambiar.Num(); i++)
		{
			int numeroEnemigo = navesACambiar[i];

			NavesEnemigas[numeroEnemigo]->SetActorHiddenInGame(true);
			NavesEnemigas[numeroEnemigo]->visibilidad = false;
		}

		tiempoTranscurrido = 0;
	}

	// Esperar un tiempo antes de hacer las naves visibles nuevamente
	if (tiempoTranscurrido >= 400 && tiempoTranscurrido < 500)
	{
		for (int i = 0; i < NavesEnemigas.Num(); i++)
		{
			if (!NavesEnemigas[i]->visibilidad)
			{
				NavesEnemigas[i]->SetActorHiddenInGame(false);
				NavesEnemigas[i]->visibilidad = true;
			}
		}
	}
}
