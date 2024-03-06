// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "AlienigenaEnemigo.h"
#include "Proyectil.h"
#include "Escenario.h"
#include "NaveAmiga.h"
#include "Obstaculo.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();
	NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();

	FVector ubicacionNave = FVector(-900.0f, 50.0f, 250.0f);
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
	FVector ubicacionAlienigena = FVector(-1200.0f, 50.0f, 245.0f);
	FRotator rotacionAlienigena = FRotator(0.0f, 0.0f, 0.0f);
	FVector ubicacionProyectil = FVector(-600.0f, 60.0f, 245.0f);
	FRotator rotacionProyectil = FRotator(0.0f, 0.0f, 0.0f);
	FVector ubicacionEscenario = FVector(-630.0f, 90.0f, 245.0f);
	FRotator rotacionEscenario = FRotator(0.0f, 0.0f, 0.0f);
	FVector ubicacionNaveAmiga = FVector(300.0f, 100.0f, 199.0f);
	FRotator rotacionNaveAmiga = FRotator(0.0f, 0.0f, 0.0f);
	FVector ubicacionObstaculo = FVector(1045.0f, -290.0f, 199.0f);
	FRotator rotacionObstaculo = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		NaveEnemiga01 = World->SpawnActor<ANaveEnemiga>(ubicacionNave, rotacionNave);
		AlienigenaEnemigo01 = World->SpawnActor<AAlienigenaEnemigo>(ubicacionAlienigena, rotacionAlienigena);
		Proyectil01 = World->SpawnActor<AProyectil>(ubicacionProyectil, rotacionProyectil);
		Escenario01 = World->SpawnActor<AEscenario>(ubicacionEscenario, rotacionEscenario);
		NaveAmiga01 = World->SpawnActor<ANaveAmiga>(ubicacionNaveAmiga, rotacionNaveAmiga);
		Obstaculo01 = World->SpawnActor<AObstaculo>(ubicacionObstaculo, rotacionObstaculo);
	}

	//NaveEnemiga01->SetResistencia(100);
}

