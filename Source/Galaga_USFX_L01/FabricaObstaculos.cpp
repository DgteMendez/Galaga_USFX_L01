// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaObstaculos.h"
#include "Asteroide.h"
//#include "Barrera.h"
//#include "Planeta.h"

AObstaculo* AFabricaObstaculos::FabricarObstaculos(FString TipoObstaculo, FVector UbicacionObstaculo)
{
	if (TipoObstaculo.Equals("Asteroide")) {
		return GetWorld()->SpawnActor<AAsteroide>(AAsteroide::StaticClass(), UbicacionObstaculo, FRotator(0, 0, 0));
	}
	//else if (TipoObstaculo.Equals("Barrera")) {
	//	return GetWorld()->SpawnActor<ABarrera>(ABarrera::StaticClass(), UbicacionObstaculo, FRotator(0, 0, 0));
	//}
	//else if (TipoObstaculo.Equals("Planeta")) {
	//	return GetWorld()->SpawnActor<APlaneta>(APlaneta::StaticClass(), UbicacionObstaculo, FRotator(0, 0, 0));
	//}
	else return nullptr; //Return null if the string isn't valid}
}
