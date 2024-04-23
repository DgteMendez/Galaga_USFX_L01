// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fabrica.h"
#include "FabricaObstaculos.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AFabricaObstaculos : public AFabrica
{
	GENERATED_BODY()
public:
	virtual AObstaculo* FabricarObstaculos(FString TipoObstaculo, FVector UbicacionObstaculo) override;
};
