// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaC2.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaC2 : public ANaveEnemigaNodriza
{
	GENERATED_BODY()

private:

	int cantObstaculos;

public:

	ANaveEnemigaNodrizaC2();

	FORCEINLINE int GetCantObstaculos() const { return cantObstaculos; }

	FORCEINLINE void SetCantidadObstaculos(int _cantidadObstaculos) { cantObstaculos = _cantidadObstaculos; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Esconderse();
	
};
