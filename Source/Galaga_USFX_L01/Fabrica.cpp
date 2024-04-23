// Fill out your copyright notice in the Description page of Project Settings.


#include "Fabrica.h"

// Sets default values
AFabrica::AFabrica()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabrica::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabrica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
ANaveEnemiga* AFabrica::OrdenarNave(FString NombreNave, FVector Ubicacion)
{
	
	ANaveEnemiga* Nave = FabricarNaves(NombreNave, Ubicacion);
	
	return Nave;
}

AObstaculo* AFabrica::OrdenarObstaculo(FString NombreObstaculo, FVector UbicacionObs)
{

	AObstaculo* Obstaculo = FabricarObstaculos(NombreObstaculo, UbicacionObs);

	return Obstaculo;
}

