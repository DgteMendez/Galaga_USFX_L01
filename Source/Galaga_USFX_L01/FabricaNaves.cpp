// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNaves.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTranporte.h"
#include "NaveEnemigaEspia.h"

ANaveEnemiga* AFabricaNaves::FabricarNaves(FString NaveKTM, FVector UbicacionNave)
{
	//Select which potion to spawn depending on the passed string
	if (NaveKTM.Equals("Caza")) {
		return GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(),UbicacionNave, FRotator(0,0,0));
	}
	else if (NaveKTM.Equals("Tranporte")) {
		return GetWorld()->SpawnActor<ANaveEnemigaTranporte>(ANaveEnemigaTranporte::StaticClass(), UbicacionNave, FRotator(0, 0, 0));
	}
	else if (NaveKTM.Equals("Espia")) {
		return GetWorld()->SpawnActor<ANaveEnemigaEspia>(ANaveEnemigaEspia::StaticClass(), UbicacionNave, FRotator(0, 0, 0));
	}
	else return nullptr; //Return null if the string isn't valid}
}
