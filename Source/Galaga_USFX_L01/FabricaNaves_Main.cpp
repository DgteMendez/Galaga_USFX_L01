// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNaves_Main.h"
#include "FabricaNaves.h"
#include "FabricaObstaculos.h"

// Sets default values
AFabricaNaves_Main::AFabricaNaves_Main()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaNaves_Main::BeginPlay()
{
	Super::BeginPlay();
	AFabrica* FabricaNaves = GetWorld()->SpawnActor<AFabricaNaves>(AFabricaNaves::StaticClass());
	AFabrica* FabricaObstaculos = GetWorld()->SpawnActor<AFabricaObstaculos>(AFabricaObstaculos::StaticClass());
	FVector ubicacionInicialNaves = FVector(800.0f, -300.0f, 215.0f);

	for (int i = 0; i < 4; i++)
	{
		ANaveEnemiga* Nave = FabricaNaves->OrdenarNave("Caza", ubicacionInicialNaves);
		NavesEnemigas.Push(Nave);
		ubicacionInicialNaves = ubicacionInicialNaves + FVector(0.0f, 200.0f, 0.0f);
	}

	ubicacionInicialNaves = FVector(1400.0f, -300.0f, 215.0f);

	for (int i = 0; i < 4; i++)
	{
		ANaveEnemiga* Nave = FabricaNaves->OrdenarNave("Tranporte", ubicacionInicialNaves);
		NavesEnemigas.Push(Nave);
		ubicacionInicialNaves = ubicacionInicialNaves + FVector(0.0f, 200.0f, 0.0f);
	}

	ubicacionInicialNaves = FVector(1100.0f, -300.0f, 215.0f);

	for (int i = 0; i < 4; i++)
	{
		ANaveEnemiga* Nave = FabricaNaves->OrdenarNave("Espia", ubicacionInicialNaves);
		NavesEnemigas.Push(Nave);
		ubicacionInicialNaves = ubicacionInicialNaves + FVector(0.0f, 200.0f, 0.0f);
	}
	AObstaculo* Obstaculo = FabricaObstaculos->OrdenarObstaculo("Asteroide", FVector(300.0f, 1000.0f, 215.0f));
	Obstaculo = FabricaObstaculos->OrdenarObstaculo("Asteroide", FVector(300.0f, -1000.0f, 215.0f));
	Obstaculo = FabricaObstaculos->OrdenarObstaculo("Barrera", FVector(500.0f, 0.0f, 215.0f));
	Obstaculo = FabricaObstaculos->OrdenarObstaculo("Planeta", FVector(500.0f, 1500.0f, 215.0f));
	Obstaculo = FabricaObstaculos->OrdenarObstaculo("Planeta", FVector(500.0f, -1500.0f, 215.0f));
}

// Called every frame
void AFabricaNaves_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

