// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "Asteroide.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AAsteroide : public AObstaculo
{
	GENERATED_BODY()
private:

	float radioExplosion;

public:

	AAsteroide();
};
