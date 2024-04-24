// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MovimientoVertical.h"
#include "Planeta.generated.h"

UCLASS()
class GALAGA_USFX_L01_API APlaneta : public AObstaculo
{
	GENERATED_BODY()

private:

	FRotator rotacion;

public:

	APlaneta();
	UMovimientoVertical* MovimientoVertical;

};
