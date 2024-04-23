// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "Obstaculo.h"
#include "Fabrica.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AFabrica : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabrica();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual ANaveEnemiga* FabricarNaves(FString NaveKTM, FVector UbicacionNave)PURE_VIRTUAL(AFabrica::FabricarNaves, return nullptr;);
	virtual AObstaculo* FabricarObstaculos(FString TipoObstaculo, FVector UbicacionObstaculo)PURE_VIRTUAL(AFabrica::FabricarObstaculos, return nullptr;);
	ANaveEnemiga* OrdenarNave(FString NombreNave, FVector Ubicacion);
	AObstaculo* OrdenarObstaculo(FString NombreObstaculo, FVector UbicacionObs);

};
