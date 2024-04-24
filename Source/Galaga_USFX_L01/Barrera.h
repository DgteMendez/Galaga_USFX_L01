// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MovimientoVertical.h"
#include "Barrera.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ABarrera : public AObstaculo
{
	GENERATED_BODY()
private:

	float tiempoAparicion;

public:

	ABarrera();
	UMovimientoVertical* MovimientoVertical;

};
